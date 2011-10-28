/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#ifndef METACHATR_JEXPR_HPP
#define METACHATR_JEXPR_HPP
#pragma once


#include <fost/core>


namespace metachatr {


    /// Describes an s-expression
    typedef struct jexpression {
        /// The expression that describes the function
        fostlib::json function;
        /// Name bindings used within the context of evaluating the expression
        fostlib::json bindings;
        /// Arguments to the function that is executed
        fostlib::json arguments;

        /// Construct a jexpression
        jexpression(const fostlib::json &function, const fostlib::json &bindings,
            const fostlib::json &arguments);
    } jexpression;


    /// Build the two parts of an s-expression from a JSON structure
    jexpression build_jexpression(const fostlib::json &);


}


#endif // METACHATR_JEXPR_HPP
