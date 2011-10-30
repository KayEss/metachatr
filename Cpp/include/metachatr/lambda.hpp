/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#ifndef METACHATR_LAMBDA_HPP
#define METACHATR_LAMBDA_HPP
#pragma once


#include <fost/core>
#include <metachatr/metachatr-fwd.hpp>


namespace metachatr {


    /// The result of a lambda expression is either a value (jexpression) or some code ready to run
    class lambda_result {
    public:
        /// The result type itself
        typedef boost::variant< jexpression, lambda > result_type;

        /// Default construct a lambda_result which just returns an empty jexpression
        lambda_result();
        /// Construct from a simple JSON value
        lambda_result(const fostlib::json &);
        /// Construct from a jexpression
        lambda_result(jexpression);
        /// Construct from a lambda
        lambda_result(lambda);

        /// Returns the result as a j-expression
        jexpression as_jexpression() const;

        /// Runs the lambda result as a function with the given arguments
        lambda_result operator() (const argument_tuple &) const;

        /// Check to see if two lambda_results are the same
        bool operator== ( const lambda_result & ) const;

    private:
        result_type m_result;
    };


    /// The name bindings for a j-expression
    typedef std::map< fostlib::string, lambda_result > context;


    namespace detail {
        class lambda_impl {
        public:
            /// Allow us to sub-class this and have destructors work correctly
            virtual ~lambda_impl();

            /// The execution of the lambda
            virtual lambda_result operator() (
                const argument_tuple &args) = 0;

            /// Convert the lambda to JSON
            virtual fostlib::json as_json() const = 0;
        };
    }


}


/// Allow the result to be output to a stream
fostlib::ostream &operator<< ( fostlib::ostream &, const metachatr::lambda_result & );


#endif // METACHATR_LAMBDA_HPP
