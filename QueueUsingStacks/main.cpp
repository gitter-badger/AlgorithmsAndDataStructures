#include "Queue.h"

#include <iostream>


int main()
{
    Queue queue;

    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << std::endl << queue.dequeue();
    std::cout << std::endl << queue.dequeue();
    std::cout << std::endl << queue.dequeue();
    std::cout << std::endl << queue.dequeue();

    std::cout << std::endl << "\n\n";
    return 0;
}