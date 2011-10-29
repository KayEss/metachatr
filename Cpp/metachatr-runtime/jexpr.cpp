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
#include <metachatr/runtime.hpp>


namespace {
    struct identity : public metachatr::detail::lambda_impl {
        metachatr::lambda_result result;
        identity(metachatr::lambda_result r)
        : result(r) {
        }

        metachatr::lambda_result operator() (metachatr::jexpression) {
            return result;
        }
    };

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
                    boost::shared_ptr<metachatr::context>(new metachatr::context), *a[0], args));
        }
        metachatr::jexpression operator() ( const fostlib::json::object_t &o ) const {
            boost::shared_ptr<metachatr::context> bindings(
                new metachatr::context);;
            for ( fostlib::json::object_t::const_iterator i(o.begin()); i != o.end(); ++i )
                if ( !i->first.empty() )
                    (*bindings)[i->first] = metachatr::lambda(new identity( metachatr::eval(
                        bindings, metachatr::build_jexpression(*i->second)) ));
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
) : m_bindings(new context), value(v) {
}

metachatr::detail::jexpression_impl::jexpression_impl(
    boost::shared_ptr< context > b, const fostlib::json &f, const argument_tuple &a
) : m_bindings(b), function(f), arguments(a) {
}

metachatr::jexpression metachatr::build_jexpression(const fostlib::json &a) {
    return boost::apply_visitor(builder(), a);
}

const metachatr::context &metachatr::detail::jexpression_impl::bindings() const {
    return *m_bindings;
}

