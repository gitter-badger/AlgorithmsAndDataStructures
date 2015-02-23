#include "LinkedList.h"

#include <iostream>
#include <stack>
#include <assert.h>

#define recursive

//==============================================================================================================================================================
LinkedList::LinkedList(Node* head) : head(head)
{

}

//==============================================================================================================================================================
LinkedList::~LinkedList()
{
    //    clearAll();
}

//==============================================================================================================================================================
void LinkedList::view()  const
{
    Node* n = head;
    while(n)
    {
        std::cout << " " << n->data;
        n = n->next;
    }
}

//==============================================================================================================================================================
void LinkedList::viewReverse1() const
{
    std::stack<int> stack;
    for(Node* n = head; n != nullptr; n = n->next)
    {
        stack.push(n->data);
    }

    while(!stack.empty())
    {
        std::cout << " " << stack.top();
        stack.pop();
    }
}

//==============================================================================================================================================================
void LinkedList::viewReverse2(Node* n) const
{
    if(n->next)
    {
        viewReverse2(n->next);
    }

    std::cout << " " << n->data;
}

//==============================================================================================================================================================
void LinkedList::addFront(int data)
{
    Node* n = new Node(data);
    n->next = head;
    head    = n;

    length++;
}

//==============================================================================================================================================================
void LinkedList::addBack(int data)
{
    Node* newNode = new Node(data);
    Node* n       = head;

    if(!head)
    {
        head = newNode;
    }
    else
    {
        while(n->next)
        {
            n = n->next;
        }

        n->next = newNode;
    }

    length++;
}

//==============================================================================================================================================================
void LinkedList::add(int position, int data)
{
    assert(position >= 0 && position <= length);

    Node* newNode = new Node(data);
    Node* curr    = head;
    Node* prev    = curr;
    int index     = 0;

    if(!head)
    {
        head = newNode;
    }
    else
    {
        while(curr && index < position)
        {
            index++;
            prev = curr;
            curr = curr->next;
        }

        if(index == 0)
        {
            addFront(data);
        }
        else
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    length++;
}

//==============================================================================================================================================================
void LinkedList::insert(int data)
{
    if(!head)
    {
        addFront(data);
    }
    else
    {
        Node* n = head;
        int pos = 0;

        while(n && data > n->data)
        {
            n = n->next;
            pos++;
        }

        add(pos, data);
    }
}

//==============================================================================================================================================================
void LinkedList::removeFront()
{
    Node* toRemove = head;
    head = head->next;

    delete toRemove;
    length--;
}

//==============================================================================================================================================================
void LinkedList::removeBack()
{
    Node* curr = head;
    Node* prev = curr;

    // avoid empty list
    if(!curr)
    {
        return;
    }

    while(curr->next)
    {
        prev = curr;
        curr = curr->next;
    }

    // treat special head case
    if(curr == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* toRemove = prev->next;
        prev->next     = nullptr;

        delete toRemove;
    }

    length--;
}

//==============================================================================================================================================================
void LinkedList::remove(int position)
{
    int index = 0;
    Node* curr = head;
    Node* prev = curr;

    if(!curr)
    {
        return;
    }

    while(index < position)
    {
        prev = curr;
        curr = curr->next;
        index++;
    }

    if(curr == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* toRemove = prev->next;
        prev->next = nullptr;

        delete toRemove;
    }

    length--;
}

//==============================================================================================================================================================
LinkedList::Node* LinkedList::getHead() const
{
    return head;
}

//==============================================================================================================================================================
void LinkedList::removeDuplicates()
{
    Node* n = head;

    while(n->next)
    {
        if(n->data == n->next->data)
        {
            Node* toRemove = n->next;
            n->next = n->next->next;

            delete toRemove;
            length--;
        }
        else
        {
            n = n->next;
        }
    }
}

//==============================================================================================================================================================
int LinkedList::getLenght() const
{
    return length;
}

//==============================================================================================================================================================
int LinkedList::getMiddle() const
{
    assert(head);

    Node* slow = head;
    Node* fast = head;

    while(fast)
    {
        if(!fast)
        {
            break;
        }
        fast = fast->next;

        if(!fast)
        {
            break;
        }
        fast = fast->next;

        slow = slow->next;
    }

    return slow->data;
}

//==============================================================================================================================================================
bool LinkedList::isCircular() const
{
    bool circular = false;

    Node* fast = head;
    Node* slow = head;

    while(fast && !circular)
    {
        if(!fast)
        {
            break;
        }
        fast = fast->next;

        if(!fast)
        {
            break;
        }
        fast = fast->next;

        slow = slow->next;

        if(fast == slow)
        {
            circular = true;
        }
    }

    return circular;
}

//==============================================================================================================================================================
int LinkedList::getLoopSize() const
{
    int loop = 0;

    if(!isCircular())
    {
        loop = -1;
    }
    else
    {
        Node* slow = head;
        Node* fast = head;

        bool finished = false;
        while(!finished)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                do
                {
                    fast = fast->next->next;
                    slow = slow->next;
                    loop++;
                }
                while(fast != slow);

                finished = true;
            }
        }
    }

    return loop;
}

//==============================================================================================================================================================
LinkedList::Node* LinkedList::getNth(int pos) const
{
    int index  = 0;
    Node* curr = head;
    Node* prev = curr;

    if(pos == -1)
    {
        return nullptr;
    }

    while(index < pos)
    {
        prev = curr;
        curr = curr->next;
        index++;
    }

    if(curr == head || index == 0)
    {
        return head;
    }
    else
    {
        return prev->next;
    }
}

//==============================================================================================================================================================
void LinkedList::makeFlat()
{
    if(isCircular())
    {
        int loopSize = getLoopSize();
        Node* ahead  = getNth(loopSize);
        Node* curr   = head;
        Node* prev   = head;

        while(curr != ahead)
        {
            curr  = curr->next;
            prev  = ahead;
            ahead = ahead->next;
        }

        prev->next = nullptr;
    }
}

//==============================================================================================================================================================
void LinkedList::makeCircular()
{
    Node* tail = getNth(length - 1);
    tail->next = head;
}

//==============================================================================================================================================================
void LinkedList::clearAll()
{
    if(isCircular())
    {
        makeFlat();
    }

    while(head)
    {
        removeFront();
    }
}

//==============================================================================================================================================================
int LinkedList::getFront() const
{
    return head->data;
}

//==============================================================================================================================================================
void LinkedList::swap(int pos1, int pos2)
{
    int distance = std::abs(pos2 - pos1);
    if(distance == 0) // no need to swap same node
    {
        return;
    }

    if(pos2 < pos1) // be consistent. Order does not matter
    {
        swap(pos1, pos2);
    }

    Node* n1     = getNth(pos1 - 1); // must always get the previous
    Node* n2     = getNth(pos2 - 1); // must always get the previous

    if(!n1) // we have to swap head
    {
        if(distance == 1) // special case
        {
            Node* tmp      = n2->next;
            Node* saveN2   = n2->next->next;
            n2->next->next = head;
            head->next     = saveN2;
            head           = tmp;
        }
        else
        {
            Node* saveN2   = n2->next->next;
            Node* saveHead = head->next;
            Node* tmp      = head;

            head->next     = n2->next;
            head           = n2->next;

            n2->next->next = saveHead;
            n2->next       = tmp;
            tmp->next      = saveN2;
        }
    }
    else
    {
        if(distance == 1) // special case of distance 1
        {
            Node* sanveN2  = n2->next->next;

            n1->next       = n2->next;
            n2->next->next = n2;
            n2->next       = sanveN2;
        }
        else
        {
            Node* saveN1   = n1->next->next;
            Node* saveN2   = n2->next->next;

            Node* tmp      = n1->next;
            n1->next       = n2->next;

            n2->next->next = saveN1;
            n2->next       = tmp;
            tmp->next      = saveN2;
        }
    }

}

//==============================================================================================================================================================
void LinkedList::reverseWithSwap()
{
    for(int i = 0; i < length / 2; i++)
    {
        swap(i, length - i - 1);
    }

}

//==============================================================================================================================================================
void LinkedList::reverseInPlace()
{
    Node* second = head->next;
    Node* third  = second->next; // because we swap and we do not want to loose information

    second->next = head;  // do the actual swap. Now 2nd points to head
    head->next   = nullptr;
    head         = second;

    if(!third) // we are done and list it too small
    {
        return;
    }

    Node* curr = third;
    Node* prev = second;

    while(curr)
    {
        Node* next = curr->next;
        curr->next = prev; // link backwards

        prev = curr;
        curr = next;
    }

    head = prev; // will be the last one
}

//==============================================================================================================================================================
int LinkedList::getNthToLast(int n)
{
    Node* n1 = head;
    Node* n2 = head;

    for(int i = 0; i < n; i++)
    {
        n1 = n1->next;
    }

    while(n1)
    {
        n1 = n1->next;
        n2 = n2->next;
    }

    return n2->data;
}

//==============================================================================================================================================================
void LinkedList::getNthToLastRecursive(Node* node, int n, int& outResult)
{
    if(node)
    {
        recursive getNthToLastRecursive(node->next, n, outResult);
    }

    static int i = 0;
    i++;

    if(i == n)
    {
        outResult = node->data;
    }
}

//==============================================================================================================================================================
void LinkedList::swapData(int pos1, int pos2)
{
    int distance = std::abs(pos2 - pos1);
    if(distance == 0) // no need to swap same node
    {
        return;
    }

    if(pos2 < pos1) // be consistent. Order does not matter
    {
        swap(pos1, pos2);
    }

    Node* n1 = getNth(pos1); // must always get the previous
    Node* n2 = getNth(pos2); // must always get the previous
    std::swap(n1->data, n2->data);
}
