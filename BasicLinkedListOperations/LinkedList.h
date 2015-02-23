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

        Node* getHead() const;
        int getLenght() const;
        int getMiddle() const;
        Node* getNth(int pos) const;

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