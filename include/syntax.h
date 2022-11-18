#ifndef PARSER_SYNTAX_H
#define PARSER_SYNTAX_H
#include <string>
#include <iostream>
#include <queue>
#include "lexema.h"
#include "automata.h"

using namespace std;



class Syntax{
    queue <Lexema> lex_res;
    queue <Lexema> syn_res;
public:
    Syntax(queue <Lexema> _lex_res): lex_res(_lex_res){}
    void polskaWrite();
    double calculate();
};

#endif
