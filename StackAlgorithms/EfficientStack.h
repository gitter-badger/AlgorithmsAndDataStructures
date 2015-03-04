#pragma once


class EfficientStack
{
    private:
        class Node
        {
            public:
                Node(int data) : data(data), next(nullptr), prev(nullptr) {}
            public:
                int data;
                Node* next;
                Node* prev;
        };

    public:
        EfficientStack();

        void push(int data);
        void pop();
        int top() const;
        int getMin() const;
        int getSize() const;

        void view() const;

    private:
        int getFront(Node* head) const;
        void addFront(Node*& head, int data);
        void removeFront(Node*& head);

    private:
        Node* headData;
        Node* minData;
        int   minValue;
        int   size;
};