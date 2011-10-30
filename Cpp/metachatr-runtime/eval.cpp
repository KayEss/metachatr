/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <fost/log>


metachatr::lambda_result metachatr::eval(
    const metachatr::context &scope,
    jexpression expression
) {
    if ( !expression->function().isnull() ) {
        fostlib::string fn_name = fostlib::coerce<fostlib::string>(expression->function());
        metachatr::context::const_iterator fp(scope.find(fn_name));
        if ( fp != scope.end() ) {
            metachatr::lambda_result fn = fp->second;
            fostlib::logging::debug("Evaluating", fn.as_json());
        }
        throw fostlib::exceptions::not_implemented("eval -- with function");
    } else
        return expression;
}
