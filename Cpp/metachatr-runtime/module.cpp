/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <boost/lambda/bind.hpp>


namespace {
    metachatr::block module(
        const fostlib::string &, const metachatr::block &scope, const fostlib::json &args
    ) {
        return args;
    }
}

metachatr::lambda metachatr::lib::module() {
    return ::module;
}
