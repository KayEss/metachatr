/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime>
#include <fost/push_back>
#include <fost/test>


FSL_TEST_SUITE( lambda );


FSL_TEST_FUNCTION( plus ) {
    fostlib::json prog;
    fostlib::push_back(prog, "+");
    fostlib::push_back(prog, 4);
    fostlib::push_back(prog, 5);

    metachatr::jexpression expr = metachatr::build_jexpression(prog);

    metachatr::context builtins;
    builtins["+"] = metachatr::lib::plus();
    metachatr::scope s(metachatr::lookup(builtins));

    metachatr::lambda_result result = metachatr::eval(s, expr);

    metachatr::lambda_result expected(fostlib::json(9));

    FSL_CHECK_EQ(result, expected);
}


FSL_TEST_FUNCTION( nested_plus ) {
    fostlib::json prog;
    fostlib::push_back(prog, "+");
    fostlib::push_back(prog, fostlib::json());
    fostlib::push_back(prog, 1, "+");
    fostlib::push_back(prog, 1, 1);
    fostlib::push_back(prog, 1, 3);
    fostlib::push_back(prog, 5);

    metachatr::jexpression expr = metachatr::build_jexpression(prog);

    metachatr::context builtins;
    builtins["+"] = metachatr::lib::plus();
    metachatr::scope s(metachatr::lookup(builtins));

    metachatr::lambda_result result = metachatr::eval(s, expr);

    metachatr::lambda_result expected(fostlib::json(9));

    FSL_CHECK_EQ(result, expected);
}

