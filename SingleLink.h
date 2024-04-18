//
// Created by Msksim on 09.04.2024.
//
#include <iostream>
#include <memory>

using namespace std;

#ifndef OOP_NEW_SINGLELINK_H
#define OOP_NEW_SINGLELINK_H

template<typename T>
class SingleLink {

private:

    struct Node {
        int data;
        unique_ptr<Node> next;
        Node(int value) : data{value}, next{nullptr} {};
    };

    int Size;
    unique_ptr<Node> head = nullptr;

public:

    SingleLink() : head{nullptr}, Size{0} {};

    ~SingleLink()
    {
        clear();
    }

    int GetSize() { return Size; }

    void del_first()
    {
        if (head == nullptr)return;
        //Node* newNode = head.get();
        head = move(head->next);
        Size--;
    }

    void put_end(T data)
    {
        if (head == nullptr) {
            head = make_unique<Node>(data);
        } else {

            Node *current = head.get();
            while (current->next != nullptr) {
                current = current->next.get();
            }
            current->next = make_unique<Node>(data);

        }
        Size++;
    }

    void clear()
    {
        while (Size)
        {
            del_first();
        }
    }


    void put_first(T data)
    {
        if (head == nullptr) {
            head = make_unique<Node>(data);
            Size++;
            return;
        }
        unique_ptr<Node> newNode = make_unique<Node>(data);
        newNode->next = std::move(head);
        head = std::move(newNode);
        Size++;
    }

    void insert(T data, int index)
    {
        Node *current = head.get();

        if (index == 0) {

            put_first(data);

        } else {

            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }

            unique_ptr<Node> newNode = make_unique<Node>(data);
            newNode->next = move(current->next);
            current->next = move(newNode);
            Size++;
        }
    }

    void removeAt(int index)
    {

        if (index == 0) {

            head = move(head->next);
            Size--;

        } else {

            Node *current = head.get();
            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }

            current->next = std::move(current->next->next);
            Size--;

        }
    }

    void pop_back()
    {
        removeAt(Size - 1);
    }

    void show() {
        if (head == nullptr) {
            std::cout << "List is empty";
            return;
        }
        Node *current = head.get();
        while (current != nullptr) {
            std::cout << current->date << " ";
            current = current->next.get();
        }
        std::cout << "size - " << Size;
    }

    int operator[](const int index)
    {
        shared_ptr<SingleLink::Node> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        return current->data;
    }

    friend std::ostream &operator<<(std::ostream &os, SingleLink &other) {
        Node *current = other.head.get();
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << std::endl;
        return os;
    }
};







#endif //OOP_NEW_SINGLELINK_H
