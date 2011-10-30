/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/jexpr.hpp>


fostlib::ostream &operator<< ( fostlib::ostream &o, const metachatr::context &c ) {
    o << "<<metachatr::context ";
    return o;
}


fostlib::ostream &operator<< (
    fostlib::ostream &o, const metachatr::argument_tuple &a
) {
    o << "<<metachatr::argument_tuple ";
    return o;
}


fostlib::ostream &operator<< ( fostlib::ostream &o, metachatr::jexpression jexpr ) {
    o << jexpr->as_json();
    return o;
}
