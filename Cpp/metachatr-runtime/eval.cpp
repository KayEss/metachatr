/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <fost/log>


metachatr::lambda_result metachatr::eval(
    metachatr::scope scope, jexpression expression
) {
    if ( !expression->function().isnull() ) {
        fostlib::string fn_name = fostlib::coerce<fostlib::string>(expression->function());
        metachatr::lambda_result fn = scope(fn_name);
        metachatr::lambda_result result = fn(scope, expression->arguments());
        fostlib::logging::debug("Evaluating", fn.as_jexpression()->as_json());
        return result;
    } else
        return expression;
}
