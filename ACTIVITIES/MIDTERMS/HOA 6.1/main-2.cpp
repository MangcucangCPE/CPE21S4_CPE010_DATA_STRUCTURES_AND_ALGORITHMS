#include <iostream>
#include <cstdlib>
#include <time.h>
#include "searchingAlgo.h"

const int max_size = 50;

int main () {

    /*
    //generate random values:
    int dataset[max_size];
    srand(time(0));
    for(int i=0; i <max_size ; i++){
        dataset[i]=rand();
        std::cout<<dataset[i]<< " "; 
    }

    std::cout<<std::endl;

    int choice;
    std::cout<<"Indicate the number to search:";
    std::cin>> choice;

    linearSearchArr(max_size, choice, dataset); 

    Node<char>* name1 = new_Node('R');
    Node<char>* name2 = new_Node('H');
    Node<char>* name3 = new_Node('I');
    Node<char>* name4 = new_Node('A');
    Node<char>* name5 = new_Node('N');
    Node<char>* name6 = new_Node('N');
    Node<char>* name7 = new_Node('E');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = nullptr;
    
    linearSearchLL(name1, 'D');
    linearSearchLL(name1, 'X');


    //generate a sorted list for the array:
    int dataset2[max_size];
    for(int i = 0 ; i < max_size; i++){ 
        dataset2[i] = i + 1;
        std::cout <<dataset2[i] << " ";
    }
    std::cout << std::endl;

    binarySearchArr(11, dataset2, max_size);
    binarySearchArr(11111, dataset2, max_size);
    */

    
    Node<char>* name1 = new_Node('A');
    Node<char>* name2 = new_Node('B');
    Node<char>* name3 = new_Node('C');
    Node<char>* name4 = new_Node('D');
    Node<char>* name5 = new_Node('E');
    Node<char>* name6 = new_Node('F');
    Node<char>* name7 = new_Node('G');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = nullptr;

    binarySearchLL(name1, 'D');    
    binarySearchLL(name1, 'Z');   

    return 0;
}