/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <boost/lambda/bind.hpp>


namespace {
    metachatr::block plus(
        const fostlib::string &, const metachatr::block &scope, const fostlib::json &args
    ) {
        double total = 0.0;
        for ( fostlib::json::const_iterator i(args.begin()); i != args.end(); ++i )
            total += metachatr::block(*i)(scope).json().get<double>().value(0.0);
        return fostlib::json(total);
    }
}

metachatr::lambda metachatr::lib::plus() {
    return ::plus;
}
