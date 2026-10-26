#include <iostream>
#include "doubly_ll.h"

    int main(){


        DoubleList<char>* head = createNode('C');
        DoubleList<char>* second = createNode('P');
        DoubleList<char>* third = createNode('E');

        // connecting the nodes;

        //connect the head node to the next node;
        head->next = second;
        second->prev = head;
        
        // 
        second->next =  third;
        third->prev = second;

        //traversal
        std::cout<<"Testing the dllTraverse List"<<std::endl;
        dllTraverse(head);

        //insert at the head
        std::cout<<"Testing the dllInserthead"<<std::endl;
        dllInsertHead ('X', &head);
        dllTraverse(head);

        //insert at the end
        std::cout<<"Testing the dllInserthead"<<std::endl;
        dllInsertHead ('0', &head);
        dllTraverse(head);
        //general insert
        std::cout<<"Testing the dllGenInsert"<<std::endl;
        dllGenInsert(second, 'A');
        dllTraverse(head);
        //delete a node
        std::cout<<"After Deleting"<<std::endl;
        dllDelete(&head, second);
        dllTraverse(head);

    }