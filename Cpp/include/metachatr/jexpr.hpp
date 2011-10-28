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


    /// Describes a j-expression
    typedef class jexpression {
    public:
        /// Construct a j-expression
        jexpression(const fostlib::json &bindings, const fostlib::json &function,
            const fostlib::json &arguments);

        /// Name bindings used within the context of evaluating the expression
        fostlib::accessors< fostlib::json > bindings;
        /// The expression that describes the function
        fostlib::accessors< fostlib::json > function;
        /// Arguments to the function that is executed
        fostlib::accessors< fostlib::json > arguments;
    } jexpression;


    /// Build the parts of a j-expression from a JSON structure
    jexpression build_jexpression(const fostlib::json &);


}


#endif // METACHATR_JEXPR_HPP
