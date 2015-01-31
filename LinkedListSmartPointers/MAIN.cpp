#include <iostream>
#include <memory>


class BasicLinkedList
{
    private:
        class Node
        {
            public:
                Node(int data) : data(data)
                {
                }

                ~Node()
                {
                    std::cout << std::endl << "destructor: " << data;
                }

                std::shared_ptr<Node> next;
                int data;
        };

    public:
        BasicLinkedList() : head(nullptr)
        {
        }

        void emptyList()
        {
            head.reset();
        }

        void view()
        {
            auto n = head;
            while(n)
            {
                std::cout << std::endl << n->data;
                n = n->next;
            }
        }

        void addNode(int n)
        {
            auto newNode  = std::make_shared<Node>(n);
            newNode->next = head;
            head          = newNode;
        }

    private:
        std::shared_ptr<Node> head;
};


int main()
{
    BasicLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    list.emptyList();
    std::cout << std::endl << "View list contents:";
    list.view();



    return 0;
}