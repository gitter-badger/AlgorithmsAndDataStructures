#include <iostream>
#include <thread>
#include <chrono>


class CircularLinkedList
{
	public:
		class Node
		{
			public:
				Node(int data, Node* next = nullptr) : data(data), next(next)	{ }

				Node* next;
				int data;
		};

		CircularLinkedList() : head(nullptr) {}
		void add(int n)
		{
			// we have an empty list
			if(!head)
			{
				head       = new Node(n); // head points to itself
				head->next = head;
			}
			else
			{
				Node* temp = head;
				while(temp->next != head) temp = temp->next;


				Node* node = new Node(n, head);
				temp->next = node;
			}
		}

		void josephusProblem(int m)
		{
			Node* temp = head;
			while(temp != temp->next)
			{
				for(int i = 1; i <= m; i++)
					temp = temp->next;
				temp->next = temp->next->next;
			}

			std::cout << std::endl << temp->data;
		}

		void removeNthPosition(int n)
		{
			Node* temp = head;
			for(int i = 1; i < n; i++)
				temp = temp->next;

			temp->next = temp->next->next;
		}

		void view()
		{
			Node* temp = head;

			do
			{
				std::cout << std::endl << temp->data;

				temp = temp->next;
				std::this_thread::sleep_for(std::chrono::milliseconds(300));
			}
			while(temp != head);
		}

	private:
		Node* head;
};

int main()
{
	CircularLinkedList linkedList;
	int n = 10;
	int m = 5;
	for(int i = 1; i <= n; i++)
		linkedList.add(i);

	linkedList.josephusProblem(m);

	std::cout << std::endl;

	return 0;
}