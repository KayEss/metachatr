/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <boost/lambda/bind.hpp>


/*
    metachatr::block
*/


metachatr::block::block() {
}
metachatr::block::block(const fostlib::json &basic)
: json(basic) {
}


namespace {
    struct evaluator : public boost::static_visitor< metachatr::block > {
        evaluator(const metachatr::block &myscope)
        : myscope(myscope) {
        }
        const metachatr::block &myscope;

        metachatr::block operator() (const fostlib::json::atom_t &t) const {
            return fostlib::json(t);
        }
        metachatr::block operator() (const fostlib::json::array_t &a) const {
            return fostlib::json(a);
        }
        metachatr::block operator() (const fostlib::json::object_t &o) const {
            return fostlib::json(o);
        }
    };

    metachatr::block eval(const metachatr::block &expr, const metachatr::block &parent) {
        return boost::apply_visitor(evaluator(parent), expr.json());
    }
}


metachatr::block metachatr::block::operator() (
    const metachatr::block &scope
) {
    return eval(*this, scope);
}


metachatr::block::binding_proxy metachatr::block::operator[] ( const fostlib::string &n ) {
    return binding_proxy(*this, n);
}


/*
    metachatr::block::binding_proxy
*/


metachatr::block::binding_proxy::binding_proxy(block &b, const fostlib::string &n)
: b(b), n(n) {
}

namespace {
    fostlib::json fn_wrapper(
        boost::function< fostlib::json ( const fostlib::json &args ) > fn,
        const fostlib::string &, const metachatr::block &, const fostlib::json &arguments
    ) {
        return fn(arguments);
    }
}
void metachatr::block::binding_proxy::operator= (
    boost::function< fostlib::json ( const fostlib::json &args ) > fn
) {
    b.bindings()[n] = boost::lambda::bind(fn_wrapper, fn,
        boost::lambda::_1, boost::lambda::_2, boost::lambda::_3);
}
