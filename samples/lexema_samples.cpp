#include <string>
#include <iostream>
#include <queue>
#include "lexema.h"
#include "arifmetic.h"

using namespace std;

int main() {
    string str = "78/5+5*2";
    Arithmetic arif;
    queue <Lexema> lex_res = arif.lex(str);
    queue <Lexema> postfix = arif.toPostfix(lex_res);
    cout << arif.calculate(postfix) << endl;
    return 0;
}