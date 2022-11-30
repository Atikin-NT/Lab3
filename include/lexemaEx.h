//
// Created by atikin on 25.11.22.
//

#ifndef PARSER_LEXEMAEX_H
#define PARSER_LEXEMAEX_H

#include <string>
#include <iostream>
#include "lexema.h"

class IExeption{
public:
    virtual void show() = 0;
};

class LexEx: public IExeption{
    Lexema lex;
    string mess;
public:
    LexEx(Lexema l, string m = "Lexema"): lex(l), mess(m) {
        show();
    }
    void show() override{
        cout << mess << " at " << lex << endl;
    }
};

class BracketEx: public IExeption{
    Lexema lex;
    string mess;
public:
    BracketEx(Lexema l, string m = "Brackets"): lex(l), mess(m) {
        show();
    }
    void show() override{
        cout << mess << " at " << lex << endl;
    }
};

class OperationEx: public IExeption{
    Lexema lex;
    string mess;
public:
    OperationEx(Lexema l, string m = "Brackets"): lex(l), mess(m) {
        show();
    }
    void show() override{
        cout << mess << " at " << lex << endl;
    }
};

#endif //PARSER_LEXEMAEX_H
