/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#ifndef METACHATR_SCOPE_HPP
#define METACHATR_SCOPE_HPP
#pragma once


#include <fost/core>


namespace metachatr {


    /// The name bindings for a j-expression
    typedef std::map< fostlib::string, lambda_result > context;


    /// Return the scope look up lambda from one of these contexts
    scope lookup(const context &);


}


#endif // METACHATR_SCOPE_HPP
