/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <boost/lambda/bind.hpp>


namespace {
//     struct list_exec : public boost::static_visitor< bool > {
//         list_exec(metachatr::block &module, bool seen_list)
//         : module(module), seen_list(seen_list) {
//         }
//         metachatr::block &module;
//         const bool seen_list;
//
//         bool operator() (const fostlib::json::atom_t &t) {
//             return false;
//         }
//         bool operator() (const fostlib::json::array_t &a) {
//             metachatr::block section = fostlib::json(a);
//             fostlib::push_back(module.json(), section(module).json());
//             return true;
//         }
//         bool operator() (const fostlib::json::object_t &o) {
//             throw fostlib::exceptions::not_implemented(
//                 "Executing an object from a module list");
//         }
//     };
//
//     /// Execute the top level of the module
//     struct first_level : public boost::static_visitor< metachatr::block > {
//         first_level(const metachatr::block &scope)
//         : scope(scope) {
//         }
//         const metachatr::block &scope;
//
//         metachatr::block operator() (const fostlib::json::atom_t &t) const {
//             throw fostlib::exceptions::not_implemented(
//                 "Loading an atom at the top level of a module");
//         }
//         metachatr::block operator() (const fostlib::json::array_t &a) const {
//             bool seen_list = false;
//             metachatr::block module(scope);
//             for ( std::size_t p(0); p != a.size(); ++p ) {
//                 list_exec op(module, seen_list);
//                 seen_list = boost::apply_visitor(op, *a[p]);
//             }
//             return module;
//         }
//         metachatr::block operator() (const fostlib::json::object_t &o) const {
//             throw fostlib::exceptions::not_implemented(
//                 "Loading an object at the top level of a module");
//         }
//     };

    class module_impl : public metachatr::detail::lambda_impl {
        metachatr::lambda_result operator() (
            const metachatr::argument_tuple &args
        ) {
            throw fostlib::exceptions::not_implemented("module.cpp -- operator()");
            //return boost::apply_visitor(first_level(scope), args);
        }
        metachatr::jexpression as_jexpression() const {
            throw fostlib::exceptions::not_implemented("module.cpp -- as_jexpression");
        }
    };
    boost::shared_ptr< metachatr::detail::lambda_impl >
        c_module_impl( new module_impl );
}

metachatr::lambda metachatr::lib::module() {
    return c_module_impl;
}
