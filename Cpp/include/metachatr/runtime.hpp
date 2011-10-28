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


namespace metachatr {


    /// A simple typedef lambda type to start with
    typedef boost::function< jexpression ( jexpression ) > lambda;


    /// Implements a scope
    typedef std::map<fostlib::string, lambda> scope;


    /// Executes an expression
    jexpression eval(const scope &s, jexpression expr);


    /// The Metachatr standard library
    namespace lib {

        /// Execute a module
        lambda module();

        /// Add numbers
        lambda plus();


    }


}


#endif // METACHATR_RUNTIME_HPP
