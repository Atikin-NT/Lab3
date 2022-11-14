﻿#include <string>
#include <iostream>
#include <queue>
#include "parser.h"
#include "automata.h"

// Лексический
// Синтаксический

using namespace std;

queue <Lexema> lex(string input) {
    queue<Lexema>res;
    input += ' ';
    string tmp = "";
    int state = 0;
    for (char c : input) {
        switch (state)
        {
            case 0:
                digit(c, tmp, res, state);
                break;
            case 1:
                operation(c, tmp, res, state);
                break;
            default:
                break;
        }
    }
    return res;
}

void print(queue <Lexema> t) {
    while (!t.empty()) {
        cout << t.front() << endl;
        t.pop();
    }
}

int main() {
    string str = "( 123 -10)/ 50 *	\t	30 \n";
    cout << str;
    queue <Lexema> lex_res;
    lex_res = lex(str);
    print(lex_res);
    return 0;
}