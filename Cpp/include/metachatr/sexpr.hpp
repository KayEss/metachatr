/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#ifndef METACHATR_SEXPR_HPP
#define METACHATR_SEXPR_HPP
#pragma once


#include <fost/core>


namespace metachatr {


    /// Describes an s-expression
    typedef std::pair<fostlib::json, fostlib::json> sexpression;


    /// Build the two parts of an s-expression from a JSON structure
    sexpression build_sexpression(const fostlib::json &);


}


#endif // METACHATR_SEXPR_HPP
