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


    class lambda_result;


    /// A lexical scope is itself implemented as a lambda
    typedef boost::function< lambda_result ( const fostlib::string & ) > scope;


}


#endif // METACHATR_SCOPE_HPP
