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
    metachatr::block eval(const metachatr::block &expr, const metachatr::block &parent);

    std::pair<fostlib::json, fostlib::json> list(
            const metachatr::block &scope, const fostlib::json::array_t a
    ) {
        std::pair<fostlib::json, fostlib::json> split(*a[0], fostlib::json());
        for ( std::size_t v(1); v < a.size(); ++v )
            fostlib::push_back(split.second, *a[v]);
        return split;
    }

    struct evaluator : public boost::static_visitor< metachatr::block > {
        evaluator(const metachatr::block &myscope)
        : myscope(myscope) {
        }
        const metachatr::block &myscope;

        metachatr::block operator() (const fostlib::json::atom_t &t) const {
            return fostlib::json(t);
        }
        metachatr::block operator() (const fostlib::json::array_t &a) const {
            std::pair<fostlib::json, fostlib::json> sexpr(list(myscope, a));
            fostlib::string fn_name = fostlib::coerce<fostlib::string>(
                eval(sexpr.first, myscope).json());
            std::map<fostlib::string, metachatr::lambda>::const_iterator lambda_p(
                myscope.bindings().find(fn_name));
            if ( lambda_p  == myscope.bindings().end() )
                throw fostlib::exceptions::not_implemented("Name not bound", fn_name);
            return lambda_p->second(fn_name, myscope, sexpr.second);
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

void metachatr::block::binding_proxy::operator= (metachatr::lambda fn) {
    b.bindings()[n] =fn;
}
