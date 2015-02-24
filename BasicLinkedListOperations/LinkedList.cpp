#include "LinkedList.h"

#include <iostream>
#include <stack>
#include <assert.h>


//==============================================================================================================================================================
LinkedList::LinkedList(Node* head) : head(head)
{
}

//=============================================================================
LinkedList::LinkedList()
{
	head = nullptr;
	length = 0;
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
void LinkedList::clearAll()
{
//     if(isCircular())
//     {
//         makeFlat();
//     }

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
void LinkedList::swapData(int pos1, int pos2)
{
    int distance = std::abs(pos2 - pos1);
    if(distance == 0) // no need to swap same node
    {
        return;
    }

    if(pos2 < pos1) // be consistent. Order does not matter
    {
        std::swap(pos1, pos2);
    }

    Node* n1 = getNth(pos1); // must always get the previous
    Node* n2 = getNth(pos2); // must always get the previous
    std::swap(n1->data, n2->data);
}

//=============================================================================
int LinkedList::getPosition(Node* n)
{
	Node* tmp = head;
	int position = 0;

	while(tmp && tmp != n)
	{
		position++;
		tmp = tmp->next;
	}

	if(!tmp)
	{
		return -1;
	}
	else
	{
		return position;
	}
}
