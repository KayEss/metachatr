/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/jexpr.hpp>


/*
    metachatr::detail::lambda_impl
*/


metachatr::detail::lambda_impl::~lambda_impl() {
}


/*
    metachatr::lambda_result
*/


const metachatr::detail::jexpression_impl *metachatr::lambda_result::operator-> () const {
    const detail::jexpression_impl *p = boost::get<detail::jexpression_impl>(&m_result);
    if ( p )
        return p;
    else
        throw fostlib::exceptions::null("This lambda doesn't have a jexpression in it");
}

