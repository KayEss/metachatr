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


const metachatr::detail::jexpression_impl *metachatr::lambda_result::operator-> () const {
    const detail::jexpression_impl *p = boost::get<detail::jexpression_impl>(&m_result);
    if ( p )
        return p;
    else {
        fostlib::exceptions::null e("This lambda doesn't have a jexpression in it");
        fostlib::insert(e.data(), "lambda-result", as_json());
        throw e;
    }
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

