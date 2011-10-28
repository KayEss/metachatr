/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime>
#include <fost/push_back>
#include <fost/test>


FSL_TEST_SUITE( jexpr );


FSL_TEST_FUNCTION( empty ) {
    fostlib::json plain;

    metachatr::jexpression_impl expr = metachatr::build_jexpression(plain);
    FSL_CHECK_EQ(expr.bindings(), metachatr::context());
    FSL_CHECK_EQ(expr.function(), fostlib::json());
    FSL_CHECK_EQ(expr.arguments(), fostlib::json());
}


FSL_TEST_FUNCTION( atom ) {
    fostlib::json plain(34);

    metachatr::jexpression_impl expr = metachatr::build_jexpression(plain);
    FSL_CHECK_EQ(expr.bindings(), metachatr::context());
    FSL_CHECK_EQ(expr.function(), fostlib::json());
    FSL_CHECK_EQ(expr.arguments(), fostlib::json(34));
}

FSL_TEST_FUNCTION( basic_list ) {
    fostlib::json plain;
    fostlib::push_back(plain, "fn");
    fostlib::push_back(plain, 34);

    metachatr::jexpression_impl expr = metachatr::build_jexpression(plain);
    FSL_CHECK_EQ(expr.bindings(), metachatr::context());
    FSL_CHECK_EQ(expr.function(), fostlib::json("fn"));
    FSL_CHECK_EQ(expr.arguments().size(), 1u);
    FSL_CHECK_EQ(expr.arguments()[0], fostlib::json(34));
}

FSL_TEST_FUNCTION( object_with_no_members ) {
    fostlib::json plain = (fostlib::json::object_t());

    metachatr::jexpression_impl expr = metachatr::build_jexpression(plain);
    FSL_CHECK_EQ(expr.bindings(), metachatr::context());
    FSL_CHECK_EQ(expr.function(), fostlib::json());
    FSL_CHECK_EQ(expr.arguments(), fostlib::json());
}

FSL_TEST_FUNCTION( object_with_member ) {
    fostlib::json plain;
    fostlib::insert(plain, "key", true);

    metachatr::jexpression_impl expr = metachatr::build_jexpression(plain);
    FSL_CHECK_EQ(expr.bindings().find("key")->second->arguments(), fostlib::json(true));
    FSL_CHECK_EQ(expr.function(), fostlib::json());
    FSL_CHECK_EQ(expr.arguments(), fostlib::json());
}

FSL_TEST_FUNCTION( object_with_member_and_code ) {
    fostlib::json plain;
    fostlib::push_back(plain, "", "fn");
    fostlib::push_back(plain, "", "key");
    fostlib::insert(plain, "key", true);

    metachatr::jexpression_impl expr = metachatr::build_jexpression(plain);
    FSL_CHECK_EQ(expr.function(), fostlib::json("fn"));
    FSL_CHECK_EQ(expr.arguments().size(), 1u);
    FSL_CHECK_EQ(expr.arguments()[0], fostlib::json("key"));
    FSL_CHECK_EQ(expr.bindings().find("key")->second->arguments(), fostlib::json(true));
}
