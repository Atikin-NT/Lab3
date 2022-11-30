#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

enum TypeElement {
    Operation,
    Value,
    None
};

class Lexema {
    string str;
    TypeElement type;
    int start;
public:
    Lexema(string _str = "", TypeElement _type = None, int _start = -1) : str(_str), type(_type), start(_start) {};
    string getStr() { return str; }
    TypeElement getType() { return type; }
    friend ostream& operator << (ostream& out, Lexema& p) {
        out << "{" << p.str << ", ";
        if (p.type == Operation) out << "operation";
        else if (p.type == Value) out << "value";
        else out << "none";
        out << ", " << p.start << "}";
        return out;
    }

    int getPriority(){
        if(type == Operation){
            if(str == "(") return 0;
            if(str == ")") return 1;
            if(str == "+" || str == "-") return 2;
            if(str == "*" || str == "/") return 3;
        }
        if(type == None) return -1;
        return -2;
    }
};
