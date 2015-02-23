#pragma once

class LinkedList
{
    public:
        class Node
        {
            public:
                Node(int data) : data(data) {}

            public:
                Node* next = nullptr;
                int data;
        };

    public:
        LinkedList(Node* head);
        LinkedList() = default;
        ~LinkedList();

        void clearAll();
        void swap(int pos1, int pos2);
        void swapData(int pos1, int pos2);

        Node* getHead() const;
        int getLenght() const;
        int getFront() const;
        int getMiddle() const;
        Node* getNth(int pos) const;
        int getNthToLast(int n);
        void getNthToLastRecursive(Node* node, int n, int& result);

        void reverseWithSwap();
        void reverseInPlace();

        bool isCircular() const;
        int getLoopSize() const;
        void makeFlat();
        void makeCircular();

        void view() const;
        void viewReverse1() const;
        void viewReverse2(Node* n) const;

        void addFront(int data);
        void addBack(int data);
        void add(int position, int data);
        void insert(int data);

        void removeFront();
        void removeBack();
        void remove(int position);
        void removeDuplicates();

    private:
        Node* head = nullptr;
        int length = 0;
};