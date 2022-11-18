#include <gtest.h>
#include <string>
#include <iostream>
#include <queue>
#include "lexema.h"
#include "automata.h"
#include "syntax.h"

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

TEST(Parser, calculate1)
{
    string str = "( 123 +10 * 2-1)/ 20\n";
    queue <Lexema> lex_res;
    lex_res = lex(str);
    Syntax syntax(lex_res);
    syntax.polskaWrite();
    EXPECT_EQ(7.1, syntax.calculate());
}

TEST(Parser, calculate2)
{
    string str = "( 123 +10 * 2-1)/ 20\n";
    queue <Lexema> lex_res;
    lex_res = lex(str);
    Syntax syntax(lex_res);
    syntax.polskaWrite();
    EXPECT_EQ(7.1, syntax.calculate());
}

TEST(Parser, calculate3)
{
    string str = "124+56*( (2-8) / 4)";
    cout << str << endl;
    queue <Lexema> lex_res;
    lex_res = lex(str);
    print(lex_res);
    Syntax syntax(lex_res);
    syntax.polskaWrite();
    EXPECT_EQ(40, syntax.calculate());
}

TEST(Parser, calculate4)
{
    string str = "78/5+5*2-4";
    queue <Lexema> lex_res;
    lex_res = lex(str);
    Syntax syntax(lex_res);
    syntax.polskaWrite();
    EXPECT_EQ(21.6, syntax.calculate());
}