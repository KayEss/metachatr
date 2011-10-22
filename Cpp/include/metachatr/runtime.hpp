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


namespace metachatr {


    /// Take the file contents and produce the ready-to-execute AST representation
    fostlib::json filehandler(const boost::filesystem::wpath &location);


}


#endif // METACHATR_RUNTIME_HPP
