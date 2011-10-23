/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <metachatr/runtime.hpp>
#include <metachatr/parser>


metachatr::block metachatr::filehandler(
    const boost::filesystem::wpath &location
) {
    fostlib::string source = fostlib::utf::load_file(location);
    return metachatr::parse(source);
}

