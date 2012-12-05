/*
    Copyright 2011-2012, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <fost/log>


namespace {
    class plus_impl : public metachatr::detail::lambda_impl {
        metachatr::lambda_result operator() (
            metachatr::scope scope, const metachatr::argument_tuple &args
        ) {
            int64_t total = 0;
            for ( metachatr::argument_tuple::const_iterator a(args.begin()); a != args.end(); ++a ) {
                metachatr::lambda_result arg_value = eval(scope, *a);
                fostlib::json number = arg_value.value();
                fostlib::log::debug("+", total, number);
                total += number.get<int64_t>().value();
            }
            return fostlib::json(total);
        }
        metachatr::jexpression as_jexpression() const {
            return metachatr::jexpression(
                new metachatr::detail::jexpression_impl(fostlib::string("+")));
        }
    };
    boost::shared_ptr< metachatr::detail::lambda_impl >
        c_plus_impl( new plus_impl );
}

metachatr::lambda metachatr::lib::plus() {
    return c_plus_impl;
}

