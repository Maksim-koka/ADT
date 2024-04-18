//
// Created by Msksim on 09.04.2024.
//

#ifndef OOP_NEW_DOUBLELINK_H
#define OOP_NEW_DOUBLELINK_H



#include <ostream>

using namespace std;

template<typename T>
class DoubleLink {
private:

    class Node
    {
    public:
        shared_ptr<Node> pNext;
        shared_ptr<Node> prev;
        T data;

        Node(T data) : data{data} {};
    };

    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;
    int size = 0;

public:
    DoubleLink(): head{nullptr}, tail{nullptr}, size{0} {};

    void del_first()
    {
        if (head == nullptr) return;
        if (head == tail) {
            head = tail = nullptr;
            return;
        }
        head = head->pNext;
        size--;
    }

    void put_end(T data){
        shared_ptr<Node> newNode = std::make_shared<Node>(data);
        if (head == nullptr) {
            head = tail = newNode;
            head->pNext = nullptr;
            size++;
            return;
        }
        newNode->prev = tail;
        tail->pNext = newNode;
        tail = newNode;
        size++;
    }

    void clear()
    {
        while (size)
        {
            del_first();
        }
    }


    int operator[](int index) const {

        shared_ptr<Node> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->pNext;
        }
        return current->data;
    }

    void put_first(T data) {

        shared_ptr<Node> newNode = make_shared<Node>(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->pNext = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }

    void insert(T data, int index)
    {

        if (index == 0)
        {
            put_first(data);
        }
        if (index == size) {
            put_end(data);
        }
        shared_ptr<Node> newNode = make_shared<Node>(data);
        shared_ptr<Node> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->pNext;
        }
        newNode->pNext = current->pNext;
        newNode->prev = current;
        current->pNext->prev = newNode;
        current->pNext = newNode;
        ++size;

    }


    void removeAt(int index)
    {
        if (index == 0)
        {
            del_first();
        }
        if (index == size - 1) {
            tail = tail->prev;
            tail->pNext = nullptr;
            return;
        }
        std::shared_ptr<Node> current = head;
        for (int i = 0; i < index; i++) {
            current = current->pNext;
        }
        current->prev->pNext = current->pNext;
        size--;
    }

    void pop_back()
    {
        if (head == nullptr)return;
        if (head == tail) {
            head = tail = nullptr;
            size--;
            return;
        }
        tail = tail->prev;
        tail->pNext = nullptr;
        size--;
    }

    // получить количество елементов в списке
    int GetSize() { return size; }

    friend std::ostream &operator<<(std::ostream &os, DoubleLink &other) {
        Node *current = other.head.get();
        while (current != nullptr) {
            os << current->data << " ";
            current = current->pNext.get();
        }
        os << std::endl;
        return os;
    }

    bool isEmpty() {
        if (size > 0) return true;
        else return false;
    }

    T index(int index) {
        Node *newNode = head.get();
        for (int i = 0; i < index; i++) {
            newNode = newNode->pNext.get();
        }
        return newNode->data;
    }

};




#endif //OOP_NEW_DOUBLELINK_H
