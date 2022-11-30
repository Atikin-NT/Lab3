//
// Created by atikin on 25.11.22.
//

#ifndef PARSER_ARIFMETIC_H
#define PARSER_ARIFMETIC_H

#include "lexema.h"
#include "lexemaEx.h"

class Arithmetic {
public:
    queue<Lexema> lex(string inp);

    void Validate(queue<Lexema> inf);

//    queue<Lexema> toCanonicPostfix(queue<Lexema> inf);  //E;E;E; => EpEpEp;;;
//    queue<Lexema> toModifiedPostfix(queue<Lexema> inf); //E;E;E; => Ep;Ep;Ep;
//
//    //calculate postfix form
//    queue<double> calculate(queue<Lexema> post);
//
//    queue<double> perform(string inp) {
//        queue<Lexema> lex_res = lex(inp);
//        Validate(lex_res);
//        queue<Lexema> synt_res = toModifiedPostfix(lex_res);
//        queue<double> res = calculate(synt_res);
//        return res;
//    }
};


#endif //PARSER_ARIFMETIC_H
