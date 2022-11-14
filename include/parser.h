#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

enum TypeElement {
    Operation,
    Value
};

class Lexema {
    string str;
    TypeElement type;
public:
    Lexema(string _str, TypeElement _type) : str(_str), type(_type) {};
    string getStr() { return str; }
    TypeElement getType() { return type; }
    friend ostream& operator << (ostream& out, Lexema& p) {
        out << "{" << p.str << ", ";
        if (p.type == Operation) {
            out << "operation";
        }
        else if (p.type == Value) {
            out << "value";
        }
        out << "}";
        return out;
    }
};
