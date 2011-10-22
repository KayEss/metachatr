/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/main>
#include <fost/unicode>
#include <metachatr/parser>


FSL_MAIN(
    L"metachatr",
    L"metachatr - Execute a Metachatr program\n"
        L"Copyright (c) 2009-2011 Kirit Saelensminde."
)( fostlib::ostream &out, fostlib::arguments &args ) {
    fostlib::string source = fostlib::utf::load_file(
        fostlib::coerce<boost::filesystem::wpath>(args[1].value()));
    fostlib::json ast = metachatr::parse(source);
    out << fostlib::json::unparse(ast, true) << std::endl;
    return 0;
}
