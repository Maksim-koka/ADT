//
// Created by Msksim on 18.04.2024.
//


template <typename T>
class Stack{
private:

    T* stack = nullptr;
    int top = -1;

public:

    void push(const T& value){
        List.put_end(value);
    }

    void pop(){
        List.pop_back();
    }

    T& peek(){
        return stack[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    int size(){
        return List.GetSize();
    }
};




#ifndef OOP_NEW_STACK_2_H
#define OOP_NEW_STACK_2_H

#endif //OOP_NEW_STACK_2_H
