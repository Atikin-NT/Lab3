#include "syntax.h"
#include <iostream>
#include <map>
#include <string>
#include <stack>

map<string, int> operations = {{"(", 0},
                             {")", 0},
                             {"-", 1},
                             {"+", 1},
                             {"*", 2},
                             {"/", 2}};

void print1(queue <Lexema> t) {
    while (!t.empty()) {
        cout << t.front() << endl;
        t.pop();
    }
}

void printStack(stack<string> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void printDoubleStack(stack<double> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


void Syntax::polskaWrite() {
    cout << endl;
    stack<string> operStack;
    int scobaCount = 0;
    int elementErrorIndex = -1;
    while(!lex_res.empty()){
        Lexema tmp = lex_res.front();
        if(tmp.getType() == Operation){
            if(tmp.getStr() == "(") {
                scobaCount++;
                elementErrorIndex = lex_res.size();
            }
            if(tmp.getStr() == ")") {
                scobaCount--;
            }
            if(tmp.getStr() == "(") {
                operStack.push(tmp.getStr());
                lex_res.pop();
                continue;
            }
            while(!operStack.empty()){
                string prevOper = operStack.top();
                if(operations[prevOper] >= operations[tmp.getStr()]){
                    if(prevOper == "(" && tmp.getStr() == ")") {
                        operStack.pop();
                        break;
                    }
                    if(prevOper != ")" && prevOper != "(") {
                        syn_res.push(Lexema(prevOper, Operation));
                    }
                    operStack.pop();
                    continue;
                }
                break;
            }
            operStack.push(tmp.getStr());
        }
        else{
            syn_res.push(tmp);
        }
        lex_res.pop();
    }
    while(!operStack.empty()){
        string prevOper = operStack.top();
        if(prevOper != ")" && prevOper != "(") {
            syn_res.push(Lexema(prevOper, Operation));
        }
        operStack.pop();
    }
    print1(syn_res);
//    if(elementErrorIndex > 0){
//        throw "error in line: " + elementErrorIndex;
//    }
//    cout << "scobaCount = " <<  scobaCount << endl;
}

double Syntax::calculate() {
    stack<double> digitStack;
    while(!syn_res.empty()){
        Lexema frontEl = syn_res.front();

        if(frontEl.getType() == Operation){
            double a = digitStack.top();
            digitStack.pop();
            double b = digitStack.top();
            digitStack.pop();
            switch(frontEl.getStr()[0]){
                case '+':
                    digitStack.push(a+b);
                    break;
                case '-':
                    digitStack.push(b-a);
                    break;
                case '*':
                    digitStack.push(a*b);
                    break;
                case '/':
                    digitStack.push(b/a);
                    break;
                default:
                    break;
            }
        }
        else{
            digitStack.push(stod(frontEl.getStr()));
        }
//        printDoubleStack(digitStack);
        syn_res.pop();
    }
    return digitStack.top();
}