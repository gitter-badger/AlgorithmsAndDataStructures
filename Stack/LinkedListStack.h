#pragma once

#include "IStack.h"


class LinkedListStack : public IStack
{
    public:
        LinkedListStack();
        virtual void push(int item) override;
        virtual int pop() override;
        virtual int top() override;
        virtual bool isEmpty() override;

    private:
        virtual void reserve(int size) override {}

        class Node
        {
            public:
                explicit Node(int data) : data(data), next(nullptr) {}
                int data;
                Node* next;
        };

        Node* head;
};