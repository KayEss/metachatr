/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>


metachatr::block::block(const fostlib::json &basic)
: json(basic) {
}


namespace {
    struct evaluator : public boost::static_visitor< fostlib::json > {
        evaluator(const metachatr::block &myscope,
            const metachatr::block &parentscope)
        : myscope(myscope), parentscope(parentscope) {
        }
        const metachatr::block &myscope, &parentscope;

        fostlib::json operator() (const fostlib::json::atom_t &t) const {
            return fostlib::json(t);
        }
        fostlib::json operator() (const fostlib::json::array_t &a) const {
            return a;
        }
        fostlib::json operator() (const fostlib::json::object_t &o) const {
            return o;
        }
    };

    fostlib::json eval(const metachatr::block &expr, const metachatr::block &parent) {
        evaluator context(expr, parent);
        return boost::apply_visitor(context, expr.json());
    }
}


metachatr::block metachatr::block::operator() (
    const metachatr::block &scope
) {
    return eval(*this, scope);
}

