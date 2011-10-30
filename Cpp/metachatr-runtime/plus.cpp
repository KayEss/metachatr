/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <fost/log>


namespace {
    class plus_impl : public metachatr::detail::lambda_impl {
        metachatr::lambda_result operator() (
            const metachatr::argument_tuple &args
        ) {
            int64_t total = 0;
            for ( metachatr::argument_tuple::const_iterator a(args.begin()); a != args.end(); ++a ) {
                metachatr::lambda_result arg_value = eval(metachatr::context(), *a);
                fostlib::logging::debug("+", total, arg_value.as_jexpression()->as_json());
            }
            return fostlib::json(total);
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

