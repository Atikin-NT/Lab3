#include <gtest.h>
#include <string>
#include <iostream>
#include <queue>
#include "lexema.h"
#include "automata.h"
#include "syntax.h"
#include "arifmetic.h"

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

TEST(Parser, lexema_check)
{
    string str = "( 123 + 23 *    8) / 5\n";
    Arithmetic arif;
    queue <Lexema> lex_res = arif.lex(str);
    int check_arr[3] = {0, 0, 0}; // 0-Oper  1-Value
    while (!lex_res.empty()) {
        Lexema lex = lex_res.front();
        if(lex.getType() == Operation) check_arr[0]++;
        if(lex.getType() == Value) check_arr[1]++;
        lex_res.pop();
    }
    EXPECT_EQ(5, check_arr[0]);
    EXPECT_EQ(4, check_arr[1]);
}

TEST(Parser, lexema_check_unknow_element)
{
    string str = "( 123 + 23 *    sin(8)) / 5\n";
    Arithmetic arif;
    EXPECT_ANY_THROW(arif.lex(str));
}

TEST(Parser, validation_check_ok)
{
    string str = "( 123 + 23 *    8) / 5\n";
    Arithmetic arif;
    queue <Lexema> lex_res = arif.lex(str);
    EXPECT_NO_THROW(arif.Validate(lex_res));
}

TEST(Parser, validation_check_brackets_error)
{
    string str = "( 123 + 23 * 8)) / 5\n";
    Arithmetic arif;
    queue <Lexema> lex_res = arif.lex(str);
    EXPECT_ANY_THROW(arif.Validate(lex_res));
}

TEST(Parser, validation_check_operation_error)
{
    string str = "( 123 ++ 23 * 8) / 5\n";
    Arithmetic arif;
    queue <Lexema> lex_res = arif.lex(str);
    EXPECT_ANY_THROW(arif.Validate(lex_res));
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