#include "Algorithm.h"
#include "Node.h"

#include <iostream>


//=============================================================================
Node* algorithm::Clone(Node* head1)
{

	// give a better name
    Node* n1    = head1;
    Node* tail2 = nullptr;
    Node* head2 = nullptr;

	// use this instead
    while(n1)
    {
        Node* n2 = new Node(n1->data);
        Node* saveN1 = n1->next;

        if(!tail2)
        {
            tail2 = n2;
            tail2->next = nullptr;
            head2 = tail2;
        }
        else
        {
            tail2->next = n2;
            tail2 = n2;
        }

        n1->next = tail2;
        tail2->prev = n1;
        n1       = saveN1;
    }

    Node* n2 = head2;
    n1 = nullptr;

    Node* saveN2Prev = n2->prev;
    while(n2)
    {
        saveN2Prev = n2->prev;
        n1 = saveN2Prev;

        n2->prev = (n1->prev != nullptr ? n1->prev->next : nullptr);

        n2 = n2->next;
    }

    return head2;
}

//=============================================================================
void algorithm::ViewPrev(Node* head)
{
    Node* n = head;

    while(n)
    {
        std::cout << n->data << " ";
        n = n->prev;
    }
}

//=============================================================================
void algorithm::ViewNext(Node* head)
{
    Node* n = head;

    while(n)
    {
        std::cout << n->data << " ";
        n = n->next;
    }
}
