#pragma once

#include "Node.h"

#include <iostream>
#include <vector>


namespace linkedlist
{
namespace singly
{
namespace impl1
{

template<typename T>
class LinkedList
{
    public:
        //================================================================================================================================================================
        LinkedList() : head(nullptr)
        {

        }

        //================================================================================================================================================================
        void append(const LinkedList& linkedlist)
        {
            Node<T>* n = head;
            while(n->next != nullptr && n->next)
            {
                n = n->next;
            }

            n->next = linkedlist.head;
        }

        //================================================================================================================================================================
        LinkedList(const LinkedList& linkedList)
        {

            // avoid self assignment
            if(this == &linkedList)
            {
                return;
            }

            if(head)
            {
                clear();
            }

            for(Node<T>* n = linkedList.head; n != nullptr; n->next)
            {
                addFront(n->data);
            }
        }

        //================================================================================================================================================================
        LinkedList(const std::vector<T>& elements)
        {
            head = nullptr;
            init(elements);
        }

        //================================================================================================================================================================
        LinkedList(Node<T>* head) : head(head)
        {

        }

        //================================================================================================================================================================
        ~LinkedList()
        {
        }

        //================================================================================================================================================================
        T getPosition(int position)
        {
            int index = 0;
            for(Node<T>* n = head; index < position && n != nullptr; n->next)
            {
                index++;
            }

            return n->data;
        }

        //================================================================================================================================================================
        void init(const std::vector<T>& elements)
        {
            for(auto& e : elements)
            {
                addBack(e);
            }
        }

        //================================================================================================================================================================
        std::vector<T> flatten()
        {
            std::vector<T> flat;

            for(Node<T>* n = head; n != nullptr; n = n->next)
            {
                flat.push_back(n->data);
            }

            return flat;
        }

        //================================================================================================================================================================
        int length()
        {
            int size = 0;
            for(Node<T>* n = head; n != nullptr; n = n->next)
            {
                size++;
            }

            return size;
        }

        //================================================================================================================================================================
        void view()
        {
            std::cout << "head -> ";
            for(Node<T>* n = head; n != nullptr; n = n->next)
            {
                std::cout << n->data << " -> ";
            }
            std::cout << "nullptr" << "\n";
        }

        //================================================================================================================================================================
        void addFront(const T& element)
        {
            Node<T>* newNode = new Node<T>(element, head);
            head = newNode;
        }

        void addBack(const T& element)
        {
            Node<T>* n = head;
            Node<T>* newNode = new Node<T>(element);

            if(!head)
            {
                head = newNode;
            }
            else
            {
                while(n->next)
                {
                    n = n->next;
                }

                n->next = newNode;
            }
        }

        //================================================================================================================================================================
        void clear()
        {
            Node<T>* n = head;

            while(n)
            {
                Node<T>* toDelete = n;
                n = n->next;

                delete toDelete;
                toDelete = nullptr;
            }

            head = nullptr;
        }

        //================================================================================================================================================================
        void remove(const T& element)
        {
            Node<T>* currNode = head;
            Node<T>* prevNode = currNode;

            while(currNode && currNode->data != element)
            {
                prevNode = currNode;
                currNode = currNode->next;
            }


            if(currNode)
                if(currNode == head)
                {
                    head = currNode->next;
                }
                else
                {
                    prevNode->next = currNode->next;
                }
        }

        //================================================================================================================================================================
        void addSorted(const T& element)
        {
            // special case. If the list is empty
            if(!head)
            {
                addFront(element);
                return;
            }

            // create the new node
            Node<T>* newNode = new Node<T>(element);

            Node<T>* node = head;
            Node<T>* prev = node;
            // search where it has to be introduced
            while(node != nullptr && newNode->data > node->data)
            {
                prev = node;
                node = node->next;
            }

            // special case if it is the first element
            if(node == head)
            {
                newNode->next = head;
                head = newNode;
            }
            // handle the other cases
            else
            {
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }

        //================================================================================================================================================================
        void removeDuplicates()
        {
            Node<T>* node = head;

            while(node->next)
            {
                if(node->data == node->next->data)
                {
                    Node<T>* toDelete = node->next;
                    node->next = node->next->next;
                    delete toDelete;
                }
                else
                {
                    node = node->next;
                }
            }
        }

        //================================================================================================================================================================
        T findMiddle()
        {
            Node<T>* slow = head;
            Node<T>* fast = head;

            // order is very important. it is evaluated left -> right
            while(fast->next && fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow->data;
        }

        //================================================================================================================================================================
        Node<T>* findLoppNode()
        {
            Node<T>* fast = head;
            Node<T>* slow = head;

            do
            {
                if(!fast)
                {
                    return nullptr;
                }

                if(!fast->next)
                {
                    return nullptr;
                }

                fast = fast->next->next;
                slow = slow->next;

            }
            while ( fast != slow);

            slow = head;

            do
            {
                slow = slow->next;
                fast = fast->next;
            }
            while (slow != fast);

            return fast;
        }

        //================================================================================================================================================================
        int loop()
        {
            Node<T>* slow = head;
            Node<T>* fast = head;

            while(true)
            {
                if(!fast)
                {
                    return -1;
                }

                fast = fast->next;

                if(!fast)
                {
                    return -1;
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
                    return size;
                }
            }

            return -1;
        }

        //================================================================================================================================================================
        void bubbleSort()
        {
            for(int i = 0; i < length(); i++)
            {
                Node<T>* curr = head;
                Node<T>* prev = curr;

                while(curr->next)
                {
                    if(curr->data > curr->next->data)
                    {
                        if(curr == head)
                        {
                            head->next = curr->next;
                            curr->next = head;
                            head = curr;
                        }
                        else
                        {
                            prev->next = curr->next;
                            curr->next = curr;
                        }
                    }

                    prev = curr;
                    curr = curr->next;
                }
            }
        }

    private:
        Node<T>* head;
};

} // namespace impl1
} // namespace single
} // namespace linkedlist