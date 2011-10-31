/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/jexpr.hpp>
#include <metachatr/lambda.hpp>
#include <fost/insert>


/*
    metachatr::detail::lambda_impl
*/


metachatr::detail::lambda_impl::~lambda_impl() {
}


/*
    metachatr::lambda_result
*/


metachatr::lambda_result::lambda_result()
: m_result(jexpression(new metachatr::detail::jexpression_impl)) {
}
metachatr::lambda_result::lambda_result(const fostlib::json &j)
: m_result(jexpression(new metachatr::detail::jexpression_impl(j))) {
}
metachatr::lambda_result::lambda_result(metachatr::jexpression expr)
: m_result(expr) {
}
metachatr::lambda_result::lambda_result(metachatr::lambda fn)
: m_result(fn) {
}


namespace {
    struct call : boost::static_visitor< metachatr::lambda_result > {
        const metachatr::argument_tuple &args;
        call(const metachatr::argument_tuple &args)
        : args(args) {
        }
        metachatr::lambda_result operator() ( metachatr::jexpression expr ) const {
            if ( args.size() != 0 )
                throw fostlib::exceptions::not_implemented("Calling a jexpression with arguments");
            return expr;
        }
        metachatr::lambda_result operator() ( metachatr::lambda fn ) const {
            return (*fn)(args);
        }
    };
}
metachatr::lambda_result metachatr::lambda_result::operator() (
    const metachatr::argument_tuple &args
) const {
    return boost::apply_visitor(call(args), m_result);
}


namespace {
    struct jexpr : boost::static_visitor< metachatr::jexpression > {
        metachatr::jexpression operator() (metachatr::jexpression expr) const {
            return expr;
        }
        metachatr::jexpression operator() (metachatr::lambda fn) const {
            return fn->as_jexpression();
        }
    };
}
metachatr::jexpression metachatr::lambda_result::as_jexpression() const {
    return boost::apply_visitor(jexpr(), m_result);
}


bool metachatr::lambda_result::operator== ( const metachatr::lambda_result &r ) const {
    return as_jexpression() == r.as_jexpression();
}


fostlib::ostream &operator<< (fostlib::ostream &o, const metachatr::lambda_result &r) {
    return o << r.as_jexpression();
}

