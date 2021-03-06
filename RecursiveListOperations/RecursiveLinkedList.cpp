#include "RecursiveLinkedList.h"
#include "Node.h"

#include <iostream>


//----------------------------------------------------------------------------------------------------------------------------------------------
LinkedList::LinkedList() : m_head(nullptr)
{

}

//----------------------------------------------------------------------------------------------------------------------------------------------
void LinkedList::addNode(int data)
{
    Node* n = new Node(data);

    if (!m_head)
    {
        m_head = n;
    }
    else
    {
        n->next = m_head;
        m_head    = n;
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void LinkedList::viewFront(Node* n)
{
    if (!n)
    {
        std::cout << "null";
        return;
    }

    std::cout << n->data << " -> ";

    viewFront(n->next);
}

//----------------------------------------------------------------------------------------------------------------------------------------------
void LinkedList::viewReverse(Node* n)
{
    if (!n)
    {
        std::cout << "null";
        return;
    }

    viewReverse(n->next);

    std::cout << " -> " << n->data ;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
Node* LinkedList::getHead()
{
    return m_head;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
int LinkedList::count(Node* n)
{
    if (!n)
    {
        return 0;
    }
    else
        return 1 + count(n->next);
}
