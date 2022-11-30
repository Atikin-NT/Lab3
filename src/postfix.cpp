#include "arifmetic.h"

using namespace std;


queue<Lexema> Arithmetic::toPostfix(queue<Lexema> lex_res) {
    cout << endl;
    stack<Lexema> operStack;
    queue<Lexema> res;
    while(!lex_res.empty()){
        Lexema tmp = lex_res.front();

        if(tmp.getType() == Operation){
            if(tmp.getStr() != "(") {
                while (!operStack.empty()) {
                    Lexema prevOper = operStack.top();
                    operStack.pop();
                    if(tmp.getPriority() <= prevOper.getPriority()){
                        res.push(prevOper);
                    }
                    else{
                        if(tmp.getStr() != ")" && prevOper.getStr() != "("){
                            operStack.push(prevOper);
                        }
                        break;
                    }
                }
            }
            if(tmp.getStr() != "(") {
                operStack.push(tmp);
            }
        }
        else{
            res.push(tmp);
        }
        lex_res.pop();
    }
    while(!operStack.empty()){
        Lexema prevOper = operStack.top();
        operStack.pop();
        res.push(prevOper);
    }
    return res;
}