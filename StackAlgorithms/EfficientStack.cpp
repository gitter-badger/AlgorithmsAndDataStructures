#include "EfficientStack.h"

#include <iostream>
#include <limits>


//==============================================================================================================================================
EfficientStack::EfficientStack()
{
    headData = nullptr;
    minData  = nullptr;
    minValue = std::numeric_limits<int>::max();
    size     = 0;
}

//==============================================================================================================================================
void EfficientStack::push(int data)
{
    minValue = data < minValue ? data : minValue;

    addFront(headData, data);
    addFront(minData, minValue);

    size++;
}

//==============================================================================================================================================
void EfficientStack::pop()
{
    removeFront(headData);
    removeFront(minData);

    size--;
}

//==============================================================================================================================================
int EfficientStack::getMin() const
{
    return getFront(minData);
}

//==============================================================================================================================================
void EfficientStack::addFront(Node*& head, int data)
{
    Node* node = new Node(data);

    if(!head)
    {
        head = node;
    }
    else
    {
        head->prev = node;
        node->next = head;
        head	   = node;
    }
}

//==============================================================================================================================================
void EfficientStack::removeFront(Node*& head)
{
    Node* toRemove = head;
    head           = head->next;
    head->prev     = nullptr;

    delete toRemove;
}

//==============================================================================================================================================
void EfficientStack::view() const
{
    Node* n = headData;
    while(n)
    {
        std::cout << n->data << " -> ";
        n = n->next;
    }

    std::cout << std::endl;

    n = minData;
    while(n)
    {
        std::cout << n->data << " -> ";
        n = n->next;
    }
}

//==============================================================================================================================================
int EfficientStack::getFront(Node* head) const
{
    return head->data;
}

//==============================================================================================================================================
int EfficientStack::top() const
{
    return getFront(headData);
}

//==============================================================================================================================================
int EfficientStack::getSize() const
{
    return size;
}
