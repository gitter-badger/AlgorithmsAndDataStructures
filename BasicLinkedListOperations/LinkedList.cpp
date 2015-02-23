#include "LinkedList.h"

#include <iostream>
#include <stack>
#include <assert.h>


//==============================================================================================================================================================
LinkedList::LinkedList(Node* head) : head(head)
{

}

//==============================================================================================================================================================
LinkedList::~LinkedList()
{
    clearAll();
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

        while(n && data < n->data)
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
    int index = 0;
    Node* curr = head;
    Node* prev = curr;

    while(index < pos)
    {
        prev = curr;
        curr = curr->next;
        index++;
    }

    if(curr == head)
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
