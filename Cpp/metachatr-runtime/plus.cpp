/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>


namespace {
    class plus_impl : public metachatr::detail::lambda_impl {
        metachatr::lambda_result operator() (metachatr::jexpression expr) {
            throw fostlib::exceptions::not_implemented("metachatr.+");
        }
        fostlib::json as_json() const {
            return fostlib::json("+");
        }
    };
    boost::shared_ptr< metachatr::detail::lambda_impl >
        c_plus_impl( new plus_impl );
}

metachatr::lambda metachatr::lib::plus() {
    return c_plus_impl;
}

