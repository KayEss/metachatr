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
            return metachatr::jexpression(fostlib::json(), fostlib::json(), fostlib::json(t));
        }
        metachatr::jexpression operator() ( const fostlib::json::array_t &a ) const {
            fostlib::json args;
            for ( std::size_t v(1); v < a.size(); ++v )
                fostlib::push_back(args, *a[v]);
            return metachatr::jexpression(*a[0], fostlib::json(), args);
        }
        metachatr::jexpression operator() ( const fostlib::json::object_t &o ) const {
            fostlib::json::object_t::const_iterator p(o.find(fostlib::string()));
            if ( p == o.end() )
                return metachatr::jexpression(fostlib::json(), o, fostlib::json());
            else
                return metachatr::build_jexpression(*p->second);
        }
    };
}


metachatr::jexpression::jexpression(
    const fostlib::json &f, const fostlib::json &b, const fostlib::json &a
) : function(f), bindings(b), arguments(a) {
}

metachatr::jexpression metachatr::build_jexpression(const fostlib::json &a) {
    return boost::apply_visitor(builder(), a);
}
