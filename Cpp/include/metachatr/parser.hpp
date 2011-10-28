/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#ifndef METACHATR_PARSER_HPP
#define METACHATR_PARSER_HPP
#pragma once


#include <fost/core>
#include <metachatr/runtime>


namespace metachatr {


    /// A simple recursive parser for .metachatr files
    fostlib::json parse(const fostlib::string &);


    /// Take the file contents and produce the ready-to-execute AST representation
    block filehandler(const boost::filesystem::wpath &location);


}


#endif // METACHATR_PARSER_HPP
