/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <boost/lambda/bind.hpp>


namespace {
    class identity : public metachatr::detail::lambda_impl {
    };
}

metachatr::lambda metachatr::eval(
    boost::shared_ptr<metachatr::context> closure,
    jexpression expression
) {
    if ( !expression->function().isnull() )
        throw fostlib::exceptions::not_implemented("eval -- with function");
    else
        throw fostlib::exceptions::not_implemented("eval -- without function");
}
