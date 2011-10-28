/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#ifndef METACHATR_PARSER_HPP
#define METACHATR_PARSER_HPP
#pragma once


#include <fost/core>


namespace metachatr {


    /// A simple recursive parser for .metachatr files
    fostlib::json parse(const fostlib::string &);


    /// Build the two parts of an s-expression from a JSON list
    std::pair<fostlib::json, fostlib::json> build_sexpression(
        const fostlib::json::array_t a);


}


#endif // METACHATR_PARSER_HPP
