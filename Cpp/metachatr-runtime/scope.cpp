/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/lambda.hpp>
#include <boost/lambda/bind.hpp>


namespace {
    metachatr::lambda_result find(const metachatr::context &c, const fostlib::string &s) {
        metachatr::context::const_iterator p(c.find(s));
        if ( p != c.end() )
            return p->second;
        else
            throw fostlib::exceptions::not_implemented("context name lookup with miss");
    }
}


metachatr::scope metachatr::lookup(const metachatr::context &c) {
    return boost::lambda::bind(find, boost::cref(c), boost::lambda::_1);
}

