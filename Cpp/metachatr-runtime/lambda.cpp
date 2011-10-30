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
    throw fostlib::exceptions::not_implemented("lambda_result::operator");
}


namespace {
    struct json : boost::static_visitor< fostlib::json > {
        template<typename T>
        fostlib::json operator() (T inner) const {
            return inner->as_json();
        }
    };
}
fostlib::json metachatr::lambda_result::as_json() const {
    return boost::apply_visitor(json(), m_result);
}

