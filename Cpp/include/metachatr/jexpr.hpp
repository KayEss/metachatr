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
    class jexpression_impl;


    /// The name bindings for a j-expression
    typedef std::map< fostlib::string, boost::shared_ptr< jexpression_impl > > context;


    /// Describes a j-expression
    class jexpression_impl {
    public:
        /// Construct a j-expression
        jexpression_impl(const context &, const fostlib::json &function,
            const fostlib::json &arguments);

        /// Name bindings used within the context of evaluating the expression
        fostlib::accessors< context > bindings;
        /// The expression that describes the function
        fostlib::accessors< fostlib::json > function;
        /// Arguments to the function that is executed
        fostlib::accessors< fostlib::json > arguments;
    };


    /// Build the parts of a j-expression from a JSON structure
    jexpression_impl build_jexpression(const fostlib::json &);


}


/// Pretty print the expression
fostlib::ostream &operator << ( fostlib::ostream &, const metachatr::jexpression_impl & );

/// Pretty print a binding context
fostlib::ostream &operator << ( fostlib::ostream &, const metachatr::context & );


#endif // METACHATR_JEXPR_HPP
