#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H


template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* next;
        DoubleList<T>* prev;
};

//creating a node function
template <typename T>
DoubleList<T> *createNode(T newData){
    //dynamic memory allocation for a new node
    DoubleList<T>* newNode = new DoubleList<T>;
    
    newNode->data= newData;

    //point it to the next node
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){
    //check if the list is empty
    if(currentNode == nullptr){
        std::cout<<"The list is empty";
        return;
    }
    DoubleList<T>* tail;
    std::cout<<"FORWARD"<<std::endl;
    //forward traverse
    while(currentNode != nullptr){
        std::cout<<currentNode->data << " ";
        tail = currentNode;
        currentNode=currentNode->next;
    }
    std::cout<<std::endl;
    //reverse traverse
    std::cout<<"REVERSE"<<std::endl;
    while (tail != nullptr){
        std::cout<<tail->prev <<" ";
        tail = tail -> prev;
    }
    std::cout<<std::endl;
}
//inserting a node to the head
template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentNode){


    //create a new node
    DoubleList<T> *newNode = createNode(newData);
    //point the newNode to the currentNode (head)
    newNode->next = *currentNode;
    //point the currentNode to the newNode
    (*currentNode)->prev = newNode;
    //updating the header pointer
    *currentNode = newNode;
}
//inserting at the End;
template <typename T>
void dllInsertEnd (T newData, DoubleList<T> *currentHead){
    //create a new node
    DoubleList<T>* newNode = createNode(newData);
    //traverse until we reach the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    //connect the new node back to the last node
    newNode->prev = currentHead;
    //connect the current node to the new node
    currentHead->next = newNode;
}

//general insert
template <typename T>
void dllGenInsert(DoubleList<T>* prevNode, T newData) {
    if (prevNode == nullptr) {
        std::cout << "Cannot insert, target node is null!" << std::endl;
        return;
    }
     DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;

//delete a node
template <typename T>
void dllDelete(DoubleList<T>** head, DoubleList<T>* nodeToDelete) {
       if (*head == nullptr || nodeToDelete == nullptr) {
        return;
    }
        if (*head == nodeToDelete) {
        *head = nodeToDelete->next;
    }
        if (nodeToDelete->next != nullptr) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
       if (nodeToDelete->prev != nullptr) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }
       delete nodeToDelete;
}

}
#endif