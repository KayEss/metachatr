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


    /// Private members of metachatr
    namespace detail {
        /// Describes the storage of a j-expression
        class jexpression_impl;
    }

    /// The j-expression as it is manipulated by the rest of the code
    typedef boost::shared_ptr< detail::jexpression_impl > jexpression;


    /// The name bindings for a j-expression
    typedef std::map< fostlib::string, jexpression > context;


    namespace detail {
        /// Describes a j-expression
        class jexpression_impl : boost::noncopyable {
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
    }

    /// Build the parts of a j-expression from a JSON structure
    jexpression build_jexpression(const fostlib::json &);


}


/// Pretty print the expression
fostlib::ostream &operator << ( fostlib::ostream &, metachatr::jexpression );

/// Pretty print a binding context
fostlib::ostream &operator << ( fostlib::ostream &, const metachatr::context & );


#endif // METACHATR_JEXPR_HPP
