/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>


metachatr::lambda metachatr::eval(
    boost::shared_ptr<metachatr::context> closure,
    jexpression expressoin
) {
    throw fostlib::exceptions::not_implemented("eval");
}
