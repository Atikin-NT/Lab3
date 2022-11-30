#ifndef PARSER_ARIFMETIC_H
#define PARSER_ARIFMETIC_H

#include "lexema.h"
#include "lexemaEx.h"

class Arithmetic {
public:
    // Lexema
    queue<Lexema> lex(string inp);

    void Validate(queue<Lexema> inf);

    //Postfix
    queue<Lexema> toPostfix(queue<Lexema> inf);

    //Calculate
    double calculate(queue<Lexema> post);
};


#endif //PARSER_ARIFMETIC_H
