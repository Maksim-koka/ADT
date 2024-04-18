#include <iostream>
#include <memory>
#include "SingleLink.h"
#include "DoubleLink.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;



int main()
{

//    SingleLink<int> lst;
//    lst.put_first(5);
//    lst.put_first(7);
//    lst.put_first(101);
//    lst.put_end(13);
//    lst.put_end(17);
//
//    cout << lst << endl;
//
//    cout << "Size of list: " << lst.GetSize() << endl;
//
//    lst.del_first();
//
//    lst.pop_back();
//
//    lst.removeAt(2);
//
//    lst.insert(666, 1);
//
//   cout << lst << endl;
//
//    cout << "-------------------" << endl;
//
//    DoubleLink<int> kst;
//    kst.put_first(8);
//    kst.put_first(3);
//    kst.put_first(12);
//    kst.put_first(52);
//    kst.put_first(45);
//
//    cout << kst << endl;
//
//    cout << "Size of list: " << kst.GetSize() << endl;
//
//    kst.del_first();
//
//    cout << kst << endl;
//
//    cout << "-------------------" << endl;
//    kst.pop_back();
//
//    cout << kst << endl;
//    cout << "-------------------" << endl;
//    kst.removeAt(2);
//
//    cout << kst << endl;
//    cout << "-------------------" << endl;
//    kst.insert(666, 1);
//
//    cout << kst << endl;

    Stack<int> myStack;

    cout << "Size: " << myStack.size() << endl;

    for (int value = 0; value < 10; value += 1){
        myStack.push(value);
    }

    cout << "Size: " << myStack.size() << endl;



    Queue<int> myQueue;

    for (int value = 0; value < 10; value ++){
        myQueue.Enqueue(value);
    }

    while (!myQueue.isEmpty()){
        cout << myQueue.peek() << " ";
        myQueue.Dequeue();
    }

    return 0;
}
