#include <iostream>
#include "queueLL.h"
#include "queueArr.h"

int main() {

    /*qNode<int>* front = nullptr;
    qNode<int>* back = nullptr;

    enqueue(1, &front, &back);
    std::cout << "front: " << front->data
              << " back: " << back->data << "\n";

    enqueue(2, &front, &back);
    enqueue(3, &front, &back);

    std::cout << "front: " << front->data
              << " back: " << back->data << "\n";

    //display ()
    display(front);

    dequeue(&front, &back);
    std::cout << "front: " << front->data
              << " back: " << back->data << "\n";

    //display ()
    display(front);

    dequeue(&front, &back);
    std::cout << "front: " << front->data
              << " back: " << back->data << "\n";

    //display ()
    display(front);

    dequeue(&front, &back);

    //display ()
    display(front);

    dequeue(&front, &back);
    */

    //object creation
    queueArr<int> q(6);
    q.Enqueue(1);
    std::cout << "Front: " << q.Front() << " | Back: " << q.Back() << " | Size: " << q.Size() << std::endl;
    q.Enqueue(2);
    std::cout << "Front: " << q.Front() << " | Back: " << q.Back() << " | Size: " << q.Size() << std::endl;
    q.Enqueue(3);
    std::cout << "Front: " << q.Front() << " | Back: " << q.Back() << " | Size: " << q.Size() << std::endl;
    q.Enqueue(4);
    std::cout << "Front: " << q.Front() << " | Back: " << q.Back() << " | Size: " << q.Size() << std::endl;
    q.Enqueue(5);
    std::cout << "Front: " << q.Front() << " | Back: " << q.Back() << " | Size: " << q.Size() << std::endl;
    q.Enqueue(6);
    std::cout << "Front: " << q.Front() << " | Back: " << q.Back() << " | Size: " << q.Size() << std::endl;
    q.Dequeue();
    std::cout<<"Front: " <<q.Front() <<" Back: " <<q.Back() <<" Size: " <<q.Size() <<std::endl;
    q.Dequeue();
    std::cout<<"Front: " <<q.Front() <<" Back: " <<q.Back() <<" Size: " <<q.Size() <<std::endl;
    return 0;
}