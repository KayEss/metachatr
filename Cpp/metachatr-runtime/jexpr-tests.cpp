/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime>
#include <fost/push_back>
#include <fost/test>


FSL_TEST_SUITE( sexpr );


FSL_TEST_FUNCTION( atom ) {
    fostlib::json plain(34);

    metachatr::jexpression expr = metachatr::build_jexpression(plain);
    FSL_CHECK_EQ(expr.first, fostlib::json());
    FSL_CHECK_EQ(expr.second, fostlib::json(34));
}

FSL_TEST_FUNCTION( basic_list ) {
    fostlib::json plain;
    fostlib::push_back(plain, "fn");
    fostlib::push_back(plain, 34);

    metachatr::jexpression expr = metachatr::build_jexpression(plain);
    FSL_CHECK_EQ(expr.first, fostlib::json("fn"));
    FSL_CHECK_EQ(expr.second.size(), 1u);
    FSL_CHECK_EQ(expr.second[0], fostlib::json(34));
}
