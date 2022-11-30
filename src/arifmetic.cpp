//
// Created by atikin on 25.11.22.
//
#include "arifmetic.h"
using namespace std;

queue<Lexema> Arithmetic::lex(string input) {
    queue<Lexema>res;
    input += ' ';
    string tmp = "";
    int state = 0;
    string op = "+-*/()";
    string sep = " \n\t";
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        switch (state)
        {
            case 0:
                if (c >= '0' && c <= '9') {
                    tmp = c;
                    state = 1;
                    break;
                }
                if (op.find(c) != string::npos) {
                    tmp = c;
                    Lexema l(tmp, Operation);
                    res.push(l);
                    state = 0;
                    break;
                }
                if (sep.find(c) != string::npos){
                    tmp = "";
                    break;
                }
                throw LexEx({ {c}, None, i}, "Unknown element");
            case 1:
                if (c >= '0' && c <= '9') {
                    tmp += c;
                    break;
                }
                if (op.find(c) != string::npos) {
                    Lexema l1(tmp, Value);
                    res.push(l1);
                    tmp = c;
                    Lexema l2(tmp, Operation);
                    res.push(l2);
                    state = 0;
                    break;
                }
                if (sep.find(c) != string::npos) {
                    Lexema l(tmp, Value);
                    res.push(l);
                    state = 0;
                    break;
                }
                throw LexEx({ {c}, None, i}, "Unknown element");
            default:
                break;
        }
    }
    return res;
}

void Arithmetic::Validate(queue<Lexema> lex) {
    int open = 0;
    int close = 0;
    Lexema current_lex;
    Lexema prev;
    while(!lex.empty()){
        current_lex = lex.front();
        if(current_lex.getStr() == "(") open++;
        else if(current_lex.getStr() == ")") close++;

        if( close > open) throw BracketEx(current_lex, "Extra )");

        if(prev.getPriority() > 1 && current_lex.getPriority() > 1 && prev.getType() == Operation && current_lex.getType() == Operation) throw OperationEx(current_lex, "Operation conflict");
        prev = current_lex;
        lex.pop();
    }
    if(open > close) throw BracketEx(current_lex, "Unclosed (");
}