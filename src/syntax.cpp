#include "syntax.h"
#include <iostream>
#include <map>
#include <string>
#include <stack>

map<char, int> operations = {{'(', 0},
                             {')', 0},
                             {'-', 1},
                             {'+', 1},
                             {'*', 2},
                             {'/', 2}};

void print1(queue <Lexema> t) {
    while (!t.empty()) {
        cout << t.front() << endl;
        t.pop();
    }
}

void printStack(stack<char> st){
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
    stack<char> operStack;
    int scobaCount = 0;
    while(!lex_res.empty()){
        Lexema tmp = lex_res.front();
        if(tmp.getType() == Operation){
            if(tmp.getStr()[0] == '(') scobaCount++;
            if(tmp.getStr()[0] == ')') scobaCount--;
            while(!operStack.empty()){
                char prevOper = operStack.top();
                if(operations[prevOper] >= operations[tmp.getStr()[0]]){
                    if(prevOper != ')' && prevOper != '(') {
                        syn_res.push(Lexema(string(1, prevOper), Operation));
                    }
                    operStack.pop();
                    continue;
                }
                break;
            }
            operStack.push(tmp.getStr()[0]);
        }
        else{
            syn_res.push(tmp);
        }
        printStack(operStack);
        lex_res.pop();
    }
    while(!operStack.empty()){
        char prevOper = operStack.top();
        if(prevOper != ')' && prevOper != '(') {
            syn_res.push(Lexema(string(1, prevOper), Operation));
        }
        operStack.pop();
    }
    print1(syn_res);
    cout << "scobaCount = " <<  scobaCount << endl;
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
        printDoubleStack(digitStack);
        syn_res.pop();
    }
    return digitStack.top();
}