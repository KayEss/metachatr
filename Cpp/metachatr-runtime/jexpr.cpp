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
    struct builder : public boost::static_visitor< metachatr::jexpression > {
        metachatr::jexpression operator() ( const fostlib::json::atom_t &t ) const {
            return metachatr::jexpression(
                new metachatr::detail::jexpression_impl(fostlib::json(t)));
        }
        metachatr::jexpression operator() ( const fostlib::json::array_t &a ) const {
            metachatr::argument_tuple args;
            for ( std::size_t v(1); v < a.size(); ++v )
                args.push_back(metachatr::build_jexpression(*a[v]));
            return metachatr::jexpression(
                new metachatr::detail::jexpression_impl(
                    metachatr::context(), *a[0], args));
        }
        metachatr::jexpression operator() ( const fostlib::json::object_t &o ) const {
            metachatr::context bindings;
            for ( fostlib::json::object_t::const_iterator i(o.begin()); i != o.end(); ++i )
                if ( !i->first.empty() )
                    bindings[i->first] = metachatr::build_jexpression(*i->second);
            fostlib::json::object_t::const_iterator p(o.find(fostlib::string()));
            if ( p == o.end() )
                return metachatr::jexpression(
                    new metachatr::detail::jexpression_impl(
                        bindings, fostlib::json(), metachatr::argument_tuple()));
            else {
                metachatr::jexpression expr(metachatr::build_jexpression(*p->second));
                return metachatr::jexpression(
                    new metachatr::detail::jexpression_impl(
                        bindings, expr->function(), expr->arguments()));
            }
        }
    };
}


metachatr::detail::jexpression_impl::jexpression_impl(
    const fostlib::json &v
) : value(v) {
}

metachatr::detail::jexpression_impl::jexpression_impl(
    const context &b, const fostlib::json &f, const argument_tuple &a
) : bindings(b), function(f), arguments(a) {
}

metachatr::jexpression metachatr::build_jexpression(const fostlib::json &a) {
    return boost::apply_visitor(builder(), a);
}
