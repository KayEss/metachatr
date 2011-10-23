/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/main>
#include <metachatr/runtime>


namespace {
    fostlib::json echo(fostlib::ostream &out, const fostlib::json &js) {
        out << fostlib::json::unparse(js, true) << std::endl;
        return js;
    }
}


FSL_MAIN(
    L"metachatr",
    L"metachatr - Execute a Metachatr program\n"
        L"Copyright (c) 2009-2011 Kirit Saelensminde."
)( fostlib::ostream &out, fostlib::arguments &args ) {
    // Build the block that describes the builtin functions
    metachatr::block builtins;
    builtins["echo"] = boost::lambda::bind(
        echo, boost::ref(out), boost::lambda::_1);
    // Load the file and print out the stream
    fostlib::json ast = metachatr::filehandler(
        fostlib::coerce<boost::filesystem::wpath>(args[1].value())).json();
    metachatr::block code(ast);
    fostlib::json result = code(builtins).json();
    out << fostlib::json::unparse(result, true) << std::endl;
    return 0;
}
