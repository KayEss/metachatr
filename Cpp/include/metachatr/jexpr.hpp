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
#include <metachatr/lambda.hpp>
#include <metachatr/scope.hpp>


namespace metachatr {


    namespace detail {
        /// Describes a j-expression
        class jexpression_impl : boost::noncopyable {
            boost::shared_ptr<context> m_bindings;
        public:
            /// Construct an empty j-jexpression
            jexpression_impl();
            /// Construct a j-expression value
            jexpression_impl(const fostlib::json &value);
            /// Construct a j-expression with only a function names
            jexpression_impl(const fostlib::string &);
            /// Construct a j-expression
            jexpression_impl(
                boost::shared_ptr< context >,
                const fostlib::json &function,
                const argument_tuple &arguments);

            /// Name bindings used within the context of evaluating the expression
            const context &bindings() const;
            /// The expression that describes the function
            fostlib::accessors< fostlib::json > function;
            /// Arguments to the function that is executed
            fostlib::accessors< argument_tuple > arguments;
            /// The value of the j-expression
            fostlib::accessors< fostlib::json > value;

            /// Return the value of the jexpression as JSON in its canonical form
            fostlib::json as_json() const;
        };
    }

    /// Build the parts of a j-expression from a JSON structure
    jexpression build_jexpression(const fostlib::json &);


}


/// Pretty print the expression
fostlib::ostream &operator << ( fostlib::ostream &, metachatr::jexpression );

/// Pretty print a binding context
fostlib::ostream &operator << ( fostlib::ostream &, const metachatr::context & );

/// Pretty print a binding context
fostlib::ostream &operator << ( fostlib::ostream &, const metachatr::argument_tuple & );


/// Allow us to compare two jexpressions for equality
inline
bool operator== (metachatr::jexpression left, metachatr::jexpression right) {
    return left->as_json() == right->as_json();
}



#endif // METACHATR_JEXPR_HPP
