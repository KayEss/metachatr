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


namespace metachatr {


    /// This type describes a Metachatr AST in an internal executable form
    class block {
    public:
        /// Build an executable block from a JSON representation
        block(const fostlib::json &);

        /// Stores the JSON representation of the code block
        fostlib::accessors<fostlib::json> json;

        /// Executes the block and returns the new form
        block operator() (const block &scope);
    };


    /// Take the file contents and produce the ready-to-execute AST representation
    block filehandler(const boost::filesystem::wpath &location);


}


#endif // METACHATR_RUNTIME_HPP
