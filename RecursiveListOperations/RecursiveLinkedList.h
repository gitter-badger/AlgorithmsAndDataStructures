#pragma once


class Node;


class LinkedList
{
    public:
        LinkedList();

        Node* getHead();

        void addNode(int data);

        void viewFront(Node* n);

        void viewReverse(Node* n);

        int count(Node* n);

    private:
        friend class Node;

        Node* m_head;
};