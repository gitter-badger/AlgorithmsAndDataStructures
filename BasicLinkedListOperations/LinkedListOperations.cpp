#include "LinkedListOperations.h"

#include <iostream>
#include <stack>


//==============================================================================================================================================================
LinkedList linkedlist::concatenate(const LinkedList& l1, const LinkedList& l2)
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
int linkedlist::josephus(int n, int m)
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

//==============================================================================================================================================================
void linkedlist::mergeAlternativeLists(const LinkedList& l1, LinkedList& l2)
{
    LinkedList::Node* n1     = l1.getHead();
    LinkedList::Node* n2     = l2.getHead();
    LinkedList::Node* prevN2 = n2;

    while(n1 && n2)
    {
        LinkedList::Node* nextN1 = n1->next;
        LinkedList::Node* nextN2 = n2->next;

        n2->next = n1;
        n1->next = nextN2;

        n1     = nextN1;
        prevN2 = n2; // in case we need to add at the end
        n2     = nextN2;
    }

    while(n1)
    {
        prevN2->next = n1;
        prevN2       = n1;
        n1           = n1->next;
    }
}

//==============================================================================================================================================================
LinkedList linkedlist::sum(const LinkedList& l1, const LinkedList& l2)
{
    // fill stack 1
    std::stack<int> stack1;
    LinkedList::Node* n1 = l1.getHead();
    while(n1)
    {
        stack1.push(n1->data);
        n1 = n1->next;
    }

    // fill stack 2
    std::stack<int> stack2;
    LinkedList::Node* n2 = l2.getHead();
    while(n2)
    {
        stack2.push(n2->data);
        n2 = n2->next;
    }


    LinkedList l3;

    int carry = 0;
    while(!stack1.empty() && !stack2.empty())
    {
        int a      = stack1.top();
        int b      = stack2.top();
        int sum    = a + b + carry;
        int result = sum % 10;
        carry      = (sum > 9 ? 1 : 0);

        l3.addFront(result);

        stack1.pop();
        stack2.pop();
    }

    while(!stack1.empty())
    {
        int a      = stack1.top();
        int sum    = a + carry;
        int result = sum % 10;
        carry      = (sum > 9 ? 1 : 0);

        l3.addFront(result);
        stack1.pop();
    }

    while(!stack2.empty())
    {
        int b = stack2.top();
        int sum = b + carry;
        int result = sum % 10;
        carry = (sum > 9 ? 1 : 0);

        l3.addFront(result);
        stack2.pop();
    }

    if(carry)
    {
        l3.addFront(carry);
    }

    return l3;
}

//==============================================================================================================================================================
LinkedList linkedlist::createFromNumber(__int64 n)
{
    LinkedList result;

    while(n)
    {
        int d = n % 10;
        result.addFront(d);
        n /= 10;
    }


    return result;
}
