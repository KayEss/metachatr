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


    class block;


    /// A Metachatr lambda
    typedef boost::function<
            block ( const fostlib::string &name, const block &scope, const fostlib::json &arguments )
        > lambda;


    /// This type describes a Metachatr AST in an internal executable form
    class block {
    public:
        /// Create an empty block
        block();

        /// Build an executable block from a JSON representation
        block(const fostlib::json &);

        /// Stores the JSON representation of the code block
        fostlib::accessors<fostlib::json, fostlib::lvalue> json;

        /// Name bindings for evaluating the nested expression
        fostlib::accessors<
            std::map<fostlib::string, lambda>, fostlib::lvalue > bindings;

        /// Executes the block and returns the new form
        block operator() (const block &scope);

        /// Used as a proxy to allow us to implement name bindings in code more easily
        class binding_proxy {
            /// Construct the binding proxy
            binding_proxy(block &, const fostlib::string &);
            block &b; fostlib::string n;
            friend class block;
        public:
            /// Bind a lambda
            void operator= ( lambda fn );
        };

        /// Allow a function that just takes some JSON to be bound to a name
        binding_proxy operator[] ( const fostlib::string & );
    };


    /// Take the file contents and produce the ready-to-execute AST representation
    block filehandler(const boost::filesystem::wpath &location);


    /// The Metachatr standard library
    namespace lib {

        /// Execute a module
        lambda module();


    }


}


#endif // METACHATR_RUNTIME_HPP
