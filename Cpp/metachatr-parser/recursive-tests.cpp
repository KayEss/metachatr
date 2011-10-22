/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/test>
#include <metachatr/parser>


FSL_TEST_SUITE( parser_parse );


FSL_TEST_FUNCTION( empty_source ) {
    FSL_CHECK_EQ(metachatr::parse(fostlib::string()),
        fostlib::json::array_t());
    FSL_CHECK_EQ(metachatr::parse("\n"),
        fostlib::json::array_t());
}

FSL_TEST_FUNCTION( single_comment ) {
    FSL_CHECK_EQ(
        fostlib::json::unparse(metachatr::parse("A comment"), false),
        "[\"A comment\"]");
}

