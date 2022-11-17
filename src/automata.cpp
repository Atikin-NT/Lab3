#include "automata.h"

string op = "+-*/()";
string sep = " \n\t";

void digit(char& c, string& tmp, queue<Lexema>& res, int& state){
    if (c >= '0' && c <= '9') {
        tmp = c;
        state = 1;
        return;
    }
    int fres = op.find(c);
    if (fres >= 0) {
        tmp = c;
        Lexema l(tmp, Operation);
        res.push(l);
        state = 0;
    }
}

void operation(char& c, string& tmp, queue<Lexema>& res, int& state){
    if (c >= '0' && c <= '9') {
        tmp += c;
        state = 1;
        return;
    }
    int fres = op.find(c);
    if (fres >= 0) {
        Lexema l1(tmp, Value);
        res.push(l1);
        tmp = c;
        Lexema l2(tmp, Operation);
        res.push(l2);
        state = 0;
        return;
    }
    fres = sep.find(c);
    if (fres >= 0) {
        Lexema l(tmp, Value);
        res.push(l);
        state = 0;
    }
}

