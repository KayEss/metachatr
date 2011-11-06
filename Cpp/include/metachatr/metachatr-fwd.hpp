/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#ifndef METACHATR_METACHATR_FWD_HPP
#define METACHATR_METACHATR_FWD_HPP
#pragma once


#include <fost/core>


namespace metachatr {


    /// Private members of metachatr
    namespace detail {
        /// Describes the storage of a j-expression
        class jexpression_impl;
        /// Describes a lambda
        class lambda_impl;
        /// Describes a lexical scope
        class scope_impl;
    }


    /// The j-expression as it is manipulated by the rest of the code
    typedef boost::shared_ptr< detail::jexpression_impl > jexpression;


    /// A simple lambda type to start with
    typedef boost::shared_ptr< detail::lambda_impl > lambda;


    /// The list of arguments to an expression
    typedef std::vector< jexpression > argument_tuple;


}


#endif // METACHATR_METACHATR_FWD_HPP
