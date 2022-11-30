#include "arifmetic.h"
#include "Stack.h"

using namespace std;

double Arithmetic::calculate(queue<Lexema> post) {
    Stack<double> digitStack;
    Lexema lex;
    while(!post.empty()){
        lex  = post.front();

        if(lex.getType() == Operation){
            if(digitStack.size() < 2) throw ArgsEx(lex, "Missing argument");
            double a , b;
            a = digitStack.pop();
            b = digitStack.pop();
            switch(lex.getStr()[0]){
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
            digitStack.push(stod(lex.getStr()));
        }
        post.pop();
    }
    return digitStack.pop();
}