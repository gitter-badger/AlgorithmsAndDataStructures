#include "LinkedListOperations.h"


//==============================================================================================================================================================
LinkedList operations::concatenate(const LinkedList& l1, const LinkedList& l2)
{
    LinkedList result(l1.getHead());

    LinkedList::Node* n = result.getHead();
    while(n->next)
    {
        n = n->next;
    }

    n->next = l2.getHead();


    return result;
}

//==============================================================================================================================================================
int operations::josephus(int n, int m)
{
    LinkedList people;
    for(int i = 0 ; i < n; i++)
    {
        people.addFront(i);
    }
    people.makeCircular();

    while(people.getLenght() != 1)
    {
        people.remove(m);
    }

    return people.getFront();
}
