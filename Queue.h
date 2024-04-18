//
// Created by Msksim on 16.04.2024.
//
#include "DoubleLink.h"

template <typename T>
class Queue{
private:
    DoubleLink<T> list;
public:

    void Enqueue(T value){
        list.put_end(value);
    }
    void Dequeue(){
        list.del_first();
    }

    bool isEmpty(){
        return !list.isEmpty();
    }

    bool isFull(){
        return list.isEmpty();
    }

    int peek(){
        int date = list.index(0);
        return date;
    }
};



#ifndef OOP_NEW_QUEUE_H
#define OOP_NEW_QUEUE_H

#endif //OOP_NEW_QUEUE_H
