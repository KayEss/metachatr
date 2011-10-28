/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/insert>
#include <fost/push_back>
#include <fost/string>
#include <metachatr/jexpr.hpp>


namespace {
    struct builder : public boost::static_visitor< metachatr::jexpression_impl > {
        metachatr::jexpression_impl operator() ( const fostlib::json::atom_t &t ) const {
            return metachatr::jexpression_impl(metachatr::context(), fostlib::json(), fostlib::json(t));
        }
        metachatr::jexpression_impl operator() ( const fostlib::json::array_t &a ) const {
            fostlib::json args;
            for ( std::size_t v(1); v < a.size(); ++v )
                fostlib::push_back(args, *a[v]);
            return metachatr::jexpression_impl(metachatr::context(), *a[0], args);
        }
        metachatr::jexpression_impl operator() ( const fostlib::json::object_t &o ) const {
            metachatr::context bindings;
            for ( fostlib::json::object_t::const_iterator i(o.begin()); i != o.end(); ++i )
                if ( !i->first.empty() )
                    bindings[i->first] = boost::shared_ptr<metachatr::jexpression_impl>(
                        new metachatr::jexpression_impl(metachatr::context(), fostlib::json(), *i->second));
            fostlib::json::object_t::const_iterator p(o.find(fostlib::string()));
            if ( p == o.end() )
                return metachatr::jexpression_impl(bindings, fostlib::json(), fostlib::json());
            else {
                metachatr::jexpression_impl expr(metachatr::build_jexpression(*p->second));
                return metachatr::jexpression_impl(bindings, expr.function(), expr.arguments());
            }
        }
    };
}


metachatr::jexpression_impl::jexpression_impl(
    const context &b, const fostlib::json &f, const fostlib::json &a
) : bindings(b), function(f), arguments(a) {
}

metachatr::jexpression_impl metachatr::build_jexpression(const fostlib::json &a) {
    return boost::apply_visitor(builder(), a);
}
