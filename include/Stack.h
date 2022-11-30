#ifndef PARSER_STACK_H
#define PARSER_STACK_H

#include "cstring"
#include "iterator"

template <class T>
class Stack{
    int last;
    int memSize;
    T* pMem;
public:
    Stack(int _memSize = 10) : last(-1), memSize(_memSize), pMem(new T[memSize]) {};;
    ~Stack() { delete[] pMem; }
    size_t size() const { return last + 1; }
    bool isEmpty() const { return last == -1; }
    void push(const T& val){
        if(last == memSize - 1){
            T* tmpMem = new T[memSize * 2];
            std::copy(pMem, pMem + memSize, tmpMem);
            delete[] pMem;
            pMem = tmpMem;
            memSize = memSize * 2;
        }
        pMem[++last] = val;
    }
    T pop() { return pMem[last--];}
};

#endif //PARSER_STACK_H
