#include <iostream>

//==============================================================================================================================================================
class Node
{
    public:
        Node(int data) : data(data)
        {
        }

    public:
        Node* next = nullptr;
        Node* down = nullptr;
        int data;
};

//==============================================================================================================================================================
Node* createMultiLevelLinkedList()
{
    Node* n1 = new Node(5);
    Node* d11 = new Node(7);
    Node* d12 = new Node(8);
    Node* d13 = new Node(30);

    Node* n2 = new Node(10);
    Node* d21 = new Node(20);
    Node* d22 = new Node(60);

    Node* n3 = new Node(19);
    Node* d31 = new Node(21);

    Node* n4 = new Node(28);
    Node* d41 = new Node(29);
    Node* d42 = new Node(30);
    Node* d43 = new Node(31);
    Node* d44 = new Node(40);

    n1->down = d11;
    d11->down = d12;
    d12->down = d13;

    n2->down = d21;
    d21->down = d22;

    n3->down = d31;

    n4->down = d41;
    d41->down = d42;
    d42->down = d43;
    d43->down = d44;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node* head = n1;
    return head;
}

//==============================================================================================================================================================
int main()
{
    Node* head = createMultiLevelLinkedList();

    Node* n = head;
    while(n)
    {
        Node* d = n->down;

        while(d)
        {
            Node* saveDown = d->down;
            Node* tmp      = head;
            Node* prev     = tmp;

            while(tmp && d->data > tmp->data)
            {
                prev = tmp;
                tmp  = tmp->next;
            }

            d->next    = prev->next;
            prev->next = d;

            d->down    = nullptr;

            d = saveDown;
        }

        n = n->next;
    }

    Node* tmp = head;
    while(tmp)
    {
        std::cout << " " << tmp->data;
        tmp = tmp->next;
    }


    return 0;
}