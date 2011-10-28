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


FSL_TEST_FUNCTION( basic_list ) {
    fostlib::json plain;
    fostlib::push_back(plain, "fn");
    fostlib::push_back(plain, 34);

    metachatr::sexpression expr = metachatr::build_sexpression(plain);
}
