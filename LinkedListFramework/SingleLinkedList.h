#pragma once

#include "LinkedList.h"
#include "Node.h"


namespace linkedlist
{
	class SingleLinkedList : public LinkedList
	{
		public:
			SingleLinkedList();

		private:
			Node* head;			
	};
}