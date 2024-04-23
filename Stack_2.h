//
// Created by Msksim on 18.04.2024.
//

#include <iostream>

template<size_t SIZE, typename T>
class Stack_2{
private:
    T stack[SIZE] = {};
    int top = -1;
public:

    void push(T value) {
        top++;
        stack[top] = value;
    }

    void pop() {
        top--;
    }

    T& peek() {
        return stack[top];
    }

    bool isEmpty() {
        if (top == -1) return true;
        return false;
    }

    bool isFull() {
        if (top == SIZE - 1) return true;
        return false;
    }
};




#ifndef OOP_NEW_STACK_2_H
#define OOP_NEW_STACK_2_H

#endif //OOP_NEW_STACK_2_H
