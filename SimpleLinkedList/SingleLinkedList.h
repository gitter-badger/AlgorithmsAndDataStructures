#pragma once

#include "IList.h"


class SingleLinkedList : public IList
{
	private:
		class Node
		{
			public:
				Node(int data, Node* next = nullptr);

				Node* next;
				int data;
		};

	public:	
		SingleLinkedList();
		~SingleLinkedList();

		virtual void view() override;
		virtual void addFront(int n) override;
		virtual void remove(int n) override;
		virtual bool find(int n) override;

	private:
		Node* head;
};