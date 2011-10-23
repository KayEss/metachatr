/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <boost/lambda/bind.hpp>


namespace {
    /// Execute the top level of the module
    struct first_level : public boost::static_visitor< metachatr::block > {
        first_level(const metachatr::block &scope)
        : scope(scope) {
        }
        const metachatr::block &scope;

        metachatr::block operator() (const fostlib::json::atom_t &t) const {
            throw fostlib::exceptions::not_implemented(
                "Plus with an atom");
        }
        metachatr::block operator() (const fostlib::json::array_t &a) const {
            return fostlib::json();
        }
        metachatr::block operator() (const fostlib::json::object_t &o) const {
            throw fostlib::exceptions::not_implemented(
                "Plus with an object");
        }
    };

    metachatr::block plus(
        const fostlib::string &, const metachatr::block &scope, const fostlib::json &args
    ) {
        return boost::apply_visitor(first_level(scope), args);
    }
}

metachatr::lambda metachatr::lib::plus() {
    return ::plus;
}
