#pragma once

#include <vector>

class LinkedList
{
    public:
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

    public:
        LinkedList(Node* head);
        LinkedList();
        ~LinkedList();

		// allow simple conversion to vector
		operator std::vector<int>();

        void clearAll();
        void swapData(int pos1, int pos2);

        Node* getHead() const;
        void setHead(Node* head);
        int getLenght() const;
        int getFront() const;
        int getMiddle() const;
        Node* getNth(int pos) const;
        int getPosition(Node* n);
        bool find(int data) const;

        void view() const;

        void addFront(int data);
        void addBack(int data);
        void add(int position, int data);
        void insert(int data);

        void removeFront();
        void removeBack();
        void remove(int position);
        void removeDuplicates();

    private:
        Node* head;
        int length;
};