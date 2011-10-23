/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/main>
#include <metachatr/runtime>


namespace {
    fostlib::json echo(fostlib::ostream &out,
            const fostlib::string &, const metachatr::block &, const fostlib::json &args) {
        out << fostlib::json::unparse(args, true) << std::endl;
        return args;
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
        echo, boost::ref(out), boost::lambda::_1, boost::lambda::_2, boost::lambda::_3);
    builtins["module"] = metachatr::lib::module();
    // Load the file and print out the stream
    fostlib::json ast = metachatr::filehandler(
        fostlib::coerce<boost::filesystem::wpath>(args[1].value())).json();
    // Execute the code in the AST
    metachatr::block code(ast);
    metachatr::block result = code(builtins);
    // Print the resultant JSON (for now)
    out << fostlib::json::unparse(result.json(), true) << std::endl;
    return 0;
}
