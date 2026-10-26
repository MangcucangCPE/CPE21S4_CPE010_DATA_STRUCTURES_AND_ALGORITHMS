#include <iostream>
#include <stack>


int main (){
    //create an object:
    std::stack<char> stack1;

    std::cout<<"Is the stack empty?" <<stack1.empty() << std::endl;
    stack1.push('r');
    std::cout<<"Is the stack empty?" <<stack1.empty() << std::endl;
    std::cout<<"Current top of the stack:"<<stack1.top()<<std::endl;
    stack1.push('h');
    std::cout<<"Current top of the stack:"<<stack1.top()<<std::endl;
    stack1.push('i');
    std::cout<<"Current top of the stack:"<<stack1.top()<<std::endl;
    std::cout<<"Is the stack empty?" <<stack1.empty() << std::endl;
    std::cout<<"What is the size of the stack?" <<stack1.size() << std::endl;

    //swap
    std::stack<char> stack2;
    stack2.push('D');

    stack1.swap(stack2);

    std::cout << "Top after swap: " << stack1.top() << std::endl;

    //emplace
    stack1.emplace('K');

    std::cout << "Top after emplace: " << stack1.top() << std::endl;
    std::cout << "size: " << stack1.size() << std::endl;


    return 0;
}