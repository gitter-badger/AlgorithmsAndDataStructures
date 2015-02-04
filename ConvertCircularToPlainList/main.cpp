#include <iostream>

//==============================================================================================================================================================
class Node
{
    public:
        Node(int data) : data(data)
        {
            next = nullptr;
        }

    public:
        Node* next;
        int data;
};

//==============================================================================================================================================================
void view_list(Node* head)
{
    Node* n = head;
    while(n)
    {
        std::cout << std::endl << n->data;
        n = n->next;
    }
}

//==============================================================================================================================================================
void circulat_to_plain(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while(true)
    {
        fast = fast->next;
        if(!fast)
        {
            return;
        }
        fast = fast->next;
        slow = slow->next;

        if(fast == slow)
        {
            int size = 0;
            do
            {
                fast = fast->next->next;
                slow = slow->next;

                size++;
            }
            while(fast != slow);

            Node* startLoopNode = slow;
            Node* n = head;

            while(n != startLoopNode)
            {
                n = n->next;
                startLoopNode = startLoopNode->next;
            }

            Node* tmp = n;
            for(int i = 0; i < size - 1; i++)
            {
                tmp = tmp->next;
            }

            tmp->next = nullptr;
            return;
        }
    }
}

//==============================================================================================================================================================
int main()
{
    // allocate nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);

    // link nodes
    Node* head = n1;
    n1->next   = n2;
    n2->next   = n3;
    n3->next   = n4;
    n4->next   = n5;
    n5->next   = n6;
    n6->next   = n7;
    n7->next   = n8;
    n8->next   = n9;
    n9->next   = n4;

    circulat_to_plain(head);
    view_list(head);

    return 0;
}