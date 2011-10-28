/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/push_back>
#include <fost/string>
#include <metachatr/jexpr.hpp>


metachatr::jexpression metachatr::build_jexpression(
    const fostlib::json &a
) {
    metachatr::jexpression split(a[0], fostlib::json());
    for ( std::size_t v(1); v < a.size(); ++v )
        fostlib::push_back(split.second, a[v]);
    return split;
}
