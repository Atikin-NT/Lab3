#include "arifmetic.h"
#include "Stack.h"

using namespace std;


queue<Lexema> Arithmetic::toPostfix(queue<Lexema> lex_res) {
    cout << endl;
    Stack<Lexema> operStack;
    queue<Lexema> res;
    while(!lex_res.empty()){
        Lexema tmp = lex_res.front();

        if(tmp.getType() == Operation){
            if(tmp.getStr() != "(") {
                while (!operStack.isEmpty()) {
                    Lexema prevOper = operStack.pop();
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
            if(tmp.getStr() != ")") {
                operStack.push(tmp);
            }
        }
        else{
            res.push(tmp);
        }
        lex_res.pop();
    }
    while(!operStack.isEmpty()){
        Lexema prevOper = operStack.pop();
        res.push(prevOper);
    }
    return res;
}