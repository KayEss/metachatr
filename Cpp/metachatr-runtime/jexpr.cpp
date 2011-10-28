/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/push_back>
#include <fost/string>
#include <metachatr/jexpr.hpp>


namespace {
    struct builder : public boost::static_visitor< metachatr::jexpression > {
        metachatr::jexpression operator() ( const fostlib::json::atom_t &t ) const {
            return std::make_pair(fostlib::json(), fostlib::json(t));
        }
        metachatr::jexpression operator() ( const fostlib::json::array_t &a ) const {
            metachatr::jexpression split(*a[0], fostlib::json());
            for ( std::size_t v(1); v < a.size(); ++v )
                fostlib::push_back(split.second, *a[v]);
            return split;
        }
        metachatr::jexpression operator() ( const fostlib::json::object_t &o ) const {
            throw fostlib::exceptions::not_implemented(
                "J-expression builder from an object");
        }
    };
}


metachatr::jexpression metachatr::build_jexpression(const fostlib::json &a) {
    return boost::apply_visitor(builder(), a);
}
