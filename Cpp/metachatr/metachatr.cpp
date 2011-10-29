/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/main>
#include <metachatr/parser>


FSL_MAIN(
    L"metachatr",
    L"metachatr - Execute a Metachatr program\n"
        L"Copyright (c) 2009-2011 Kirit Saelensminde."
)( fostlib::ostream &out, fostlib::arguments &args ) {
    // Build the block that describes the builtin functions
    metachatr::context builtins;
    builtins["module"] = metachatr::lib::module();
//     builtins["+"] = metachatr::lib::plus();
    // Load the file
    metachatr::jexpression ast = metachatr::filehandler(
        fostlib::coerce<boost::filesystem::wpath>(args[1].value()));
    // Buld the s-expression we will execute
    ast->function(fostlib::json("module"));
    // Execute the code in the AST
    // Print the resultant JSON (for now)
//     out << fostlib::json::unparse(result.json(), true) << std::endl;
    return 0;
}
