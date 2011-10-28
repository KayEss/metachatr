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
    metachatr::scope builtins;
    builtins["module"] = metachatr::lib::module();
//     builtins["+"] = metachatr::lib::plus();
//     // Load the file
//     fostlib::json ast = metachatr::filehandler(
//         fostlib::coerce<boost::filesystem::wpath>(args[1].value())).json();
//     // Buld the s-expression we will execute
//     fostlib::json sexpr;
//     fostlib::push_back(sexpr, "module");
//     for ( fostlib::json::const_iterator i(ast.begin()); i != ast.end(); ++i )
//         fostlib::push_back(sexpr, *i);
//     // Execute the code in the AST
//     metachatr::block code(sexpr);
//     metachatr::block result = code(builtins);
//     // Print the resultant JSON (for now)
//     out << fostlib::json::unparse(result.json(), true) << std::endl;
    return 0;
}
