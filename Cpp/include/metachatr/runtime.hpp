/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#ifndef METACHATR_RUNTIME_HPP
#define METACHATR_RUNTIME_HPP
#pragma once


#include <fost/core>
#include <fost/unicode>
#include <metachatr/jexpr.hpp>
#include <metachatr/lambda.hpp>
#include <metachatr/scope.hpp>


namespace metachatr {


    /// Return a lambda which can be evaluated at any time
    lambda_result eval(scope, jexpression);


    /// The Metachatr standard library
    namespace lib {

        /// Execute a module
        lambda module();

        /// Add numbers
        lambda plus();


    }


}


#endif // METACHATR_RUNTIME_HPP
