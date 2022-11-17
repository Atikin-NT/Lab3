//
// Created by atikin on 14.11.22.
//

#ifndef PARSER_AUTOMATA_H
#define PARSER_AUTOMATA_H

#include <string>
#include <queue>
#include "lexema.h"
using namespace std;

void digit(char& c, string& tmp, queue<Lexema>& res, int& state);

void operation(char& c, string& tmp, queue<Lexema>& res, int& state);

#endif //PARSER_AUTOMATA_H
