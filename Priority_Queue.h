//
// Created by Msksim on 22.04.2024.
//

#include <vector>
#include <iostream>
#include "DoubleLink.h"
using namespace std;


class Priority_Queue{
private:

    int * Wait;
    int * Pri;
    int MaxQueueLength;
    int QueueLength;


public:

    void Show(){
        cout << "\n-------------------------------------\n";
        for (int i = 0; i<QueueLength; i++) {
            for(int p = 0; p<QueueLength; p++) {
                if(Pri[p] == i) {

                    cout << Wait[p] << " - " << Pri[p] << "\n\n";
                }
            }
        }
    }

    ~Priority_Queue()
    {
        delete[]Wait;
        delete[]Pri;
    }

    Priority_Queue(int m)
    {
        //получаем размер
        MaxQueueLength=m;
        //создаем очередь
        Wait=new int[MaxQueueLength];
        Pri=new int[MaxQueueLength];
        // Изначально очередь пуста
        QueueLength = 0;
    }

    void Clear()
    {
        QueueLength = 0;
    }

    bool IsEmpty()
    {
        return QueueLength == 0;
    }

    bool IsFull()
    {
        return QueueLength == MaxQueueLength;
    }

    int GetCount()
    {
        return QueueLength;
    }

    void Add(int c,int p)
    {
        if(!IsFull()){
            Wait[QueueLength] = c;
            Pri[QueueLength] = p;
            QueueLength++;
        }
    }

    int Extract()
    {
        // Если в очереди есть элементы, то возвращаем тот,
        // у которого наивысший приоритет и сдвигаем очередь
        if(!IsEmpty()){


            //пусть приоритетный элемент - нулевой
            int max_pri=Pri[0];
            //а приоритетный индекс = 0
            int pos_max_pri=0;

            //ищем приоритет
            for(int i=1;i<QueueLength;i++)
                //если встречен более приоритетный элемент
                if(max_pri<Pri[i]){
                    max_pri=Pri[i];
                    pos_max_pri=i;
                }

            //вытаскиваем приоритетный элемент
            int temp1=Wait[pos_max_pri];
            int temp2=Pri[pos_max_pri];

            //сдвинуть все элементы
            for(int i=pos_max_pri;i<QueueLength-1;i++){
                Wait[i]=Wait[i+1];
                Pri[i]=Pri[i+1];
            }
            //уменьшаем количество
            QueueLength--;
            // возврат извлеченного элемента
            return temp1;

        }
        else return -1;
    }

    int delet(int del)
    {
        int found;
        // Если в очереди есть элементы, то возвращаем тот,
        // у которого наивысший приоритет и сдвигаем очередь
        if(!IsEmpty()){


            for(int i = 0; i<QueueLength; i++){
                if(del == Wait[i])
                    found = i;
            }

            //вытаскиваем приоритетный элемент
            int temp1=Wait[found];
            int temp2=Pri[found];

            //сдвинуть все элементы
            for(int i=found;i<QueueLength-1;i++){
                Wait[i]=Wait[i+1];
                Pri[i]=Pri[i+1];
            }
            //уменьшаем количество
            QueueLength--;
            // возврат извлеченного элемента
            return temp1;

        }
        else return -1;
    }

};

#ifndef OOP_NEW_PRIORITY_QUEUE_H
#define OOP_NEW_PRIORITY_QUEUE_H

#endif //OOP_NEW_PRIORITY_QUEUE_H
