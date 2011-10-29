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
        /// Describes a lambda
        class lambda_impl;
    }


    /// The j-expression as it is manipulated by the rest of the code
    typedef boost::shared_ptr< detail::jexpression_impl > jexpression;

    /// A simple lambda type to start with
    typedef boost::shared_ptr< detail::lambda_impl > lambda;

    /// The result of a lambda expression is either a value (jexpression) or some code ready to run
    class lambda_result {
    public:
        /// The result type itself
        typedef boost::variant< jexpression, lambda > result_type;

        /// Construct from a jexpression
        lambda_result(jexpression);
        /// Construct from a lambda
        lambda_result(lambda);

        /// Returns a jexpression from this result
        const metachatr::detail::jexpression_impl *operator-> () const;

    private:
        result_type m_result;
    };


    namespace detail {
        class lambda_impl {
        public:
            /// Allow us to sub-class this and have destructors work correctly
            virtual ~lambda_impl();
            /// The execution of the lambda
            virtual lambda_result operator() (jexpression) = 0;
        };
    }


    /// The name bindings for a j-expression
    typedef std::map< fostlib::string, lambda > context;

    /// The list of arguments to an expression
    typedef std::vector< jexpression > argument_tuple;


    namespace detail {
        /// Describes a j-expression
        class jexpression_impl : boost::noncopyable {
            boost::shared_ptr<context> m_bindings;
        public:
            /// Construct a j-expression value
            jexpression_impl(const fostlib::json &value);
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


#endif // METACHATR_JEXPR_HPP
