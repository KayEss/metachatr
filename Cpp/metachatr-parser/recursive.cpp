/*
    Copyright 2011, Kirit Saelensminde. http://www.kirit.com/
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <fost/push_back>
#include <fost/string>
#include <metachatr/parser.hpp>


using namespace fostlib;


json metachatr::parse(const string &s) {
    json ast;
    string block;
    utf32 p = 0;
    for ( string::const_iterator c(s.begin()); c != s.end(); ++c ) {
        utf32 t = *c;
        if ( t != '\n' && p == '\n' && (t == ' ') != (block[0] == ' ') ) {
            if ( block[0] == ' ' )
                push_back(ast, json::parse(block));
            else if ( !block.empty() && !fostlib::trim(block).isnull() )
                push_back(ast, block);
            block = string();
        }
        if ( t != '\r' )
            block += t;
        p = t;
    }
    if ( !block.empty() && !fostlib::trim(block).isnull() )
        push_back(ast, block);
    return ast;
}
