#include <iostream>
#include <stack>


class Queue
{
    public:
        void enqueue(int val)
        {
            data.push(val);
        }

        int dequeue()
        {
            while(!data.empty())
            {
                buffer.push(data.top());
                data.pop();
            }

            int front = buffer.top();
            buffer.pop();

            while(!buffer.empty())
            {
                data.push(buffer.top());
                buffer.pop();
            }

            return front;
        }

    private:
        std::stack<int> data;
        std::stack<int> buffer;
};


int main()
{
    Queue queue;

    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << std::endl << queue.dequeue();
    std::cout << std::endl << queue.dequeue();
    std::cout << std::endl << queue.dequeue();
    std::cout << std::endl << queue.dequeue();

    std::cout << std::endl << "\n\n";
    return 0;
}