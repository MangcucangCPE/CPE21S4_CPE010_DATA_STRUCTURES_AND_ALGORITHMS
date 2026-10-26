#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

template <typename T>
class qNode {
public:
    T data;
    qNode<T>* next;
};

//creating the new node
template <typename T>
qNode<T>* new_node(T newData) {
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {
    //create a new node:
    qNode<T>* newNode = new_node<T>(newData);

    //inserting into an empty queue

    //how do we know that the queue is empty?
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        //assign the frontPtr to the newNode
        (*frontPtr) = newNode;

        //assign the backPtr to the newNode
        (*backPtr) = newNode;

        return;
    }

    //point the back next to the newNode:
    (*backPtr)->next = newNode;

    //the newnode will be the new backPtr
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
    //how to detemerin if the queue is empty?
    if ((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        std::cout << "the queue is empty. Nothing to dequeue\n";
        return;
    }

    //creating a temporary pointer
    qNode<T>* tempPtr = nullptr;

    //store the frontPtr to the tempPtr
    tempPtr = (*frontPtr);

    //check if queue has only 1 node left
    if ((*frontPtr) == (*backPtr)) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;

        delete tempPtr;
        return;
    }

    //update the frontPtr
    (*frontPtr) = (*frontPtr)->next;

    //point the temp -> to null
    tempPtr->next = nullptr;

    delete tempPtr;
}

//display all items in the queue: check the traverse in singlyLL
template <typename T>
void display(qNode<T>* frontPtr) {

    if (frontPtr == nullptr) {
        std::cout << "the queue is empty.\n";
        return;
    }

    qNode<T>* tempPtr = frontPtr;

    while (tempPtr != nullptr) {
        std::cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }

    std::cout << "\n";
}

#endif