#include "LinkedLists.h"

LinkedLists::LinkedLists()
{

}

LinkedLists::~LinkedLists()
{

}

ListNode* LinkedLists::MakeNode(ListNode** head, int d)
{
	ListNode* newNode = new ListNode;
	ListNode* last = *head;

	newNode->data = d;
	newNode->next = nullptr;

	if (*head == nullptr) //Check if the head contains a node if head == nullptr
	{
		*head = newNode;
		return newNode;
	}

	//Loop to find the next node that points to a nullptr, so we can place a new node here
	while (last->next != nullptr)
	{
		last = last->next;
	}

	last->next = newNode;

	return newNode;

}



ListNode* LinkedLists::InsertFirst(ListNode** head, int d)
{
	ListNode* newNode = new ListNode; //create a node

	newNode->data = d; // assign data to a value 
	newNode->next = *head; //set next of newNode as head
	*head = newNode; //move the head to point newNode at the front

	return newNode;
}

void LinkedLists::InsertAfter(ListNode* lastNode, int d)
{
	if (lastNode == nullptr)
	{
		std::cout << lastNode << " cannot be null" << std::endl;
		return;
	}

	ListNode* newNode = new ListNode; //create a node
	newNode->data = d;//assign data to a value
	newNode->next = lastNode->next; //set next of newNode as next of lastNode
	lastNode->next = newNode; //set next of lastNode as newNode
}

void LinkedLists::DeleteList(ListNode** node)
{
	ListNode* pTemp = *node;
	ListNode* next;

	while (pTemp != nullptr)
	{
		next = pTemp->next;
		delete pTemp;
		pTemp = next;
	}
	*node = nullptr;
}

void LinkedLists::DeleteAfter(ListNode* node)
{
	ListNode* pTemp;
	if (node != nullptr && node->next != nullptr)
	{
		pTemp = node->next;
		node->next = pTemp->next;
		delete pTemp;
	}
}

ListNode* LinkedLists::GetNode(ListNode* node, int pos)
{
	int count = 0;

	while (node != nullptr)
	{
		if (count == pos) // if count equal to pos, then output the node in the position
		{
			std::cout << "Data stored at position " << pos << " is: " << node->data << std::endl;
			return node;
		}
		count++;
		node = node->next;
	}
	//if it is not a valid position
	std::cout << pos << " was not a  valid position..." << std::endl;
	return nullptr;
}

ListNode* LinkedLists::Find(ListNode* node, int val)
{
	
	while (node != nullptr)
	{
		if (node->data == val)
		{
			std::cout << "Node Address of the value " << node->data << ": " << node << std::endl;
			return node;
			
		}
		node = node->next;
		
	}
	return nullptr; //val not in list
	
}

void LinkedLists::DeletefromPosition(ListNode* node, int pos)
{
	pos = pos - 1;
	int count = 0;
	ListNode* pTemp;
	while (node != nullptr)
	{
		if (count == pos)
		{
			
			
			if (node != nullptr && node->next != nullptr)
			{
				pTemp = node->next;
				node->next = pTemp->next;
				delete pTemp;
			}

			
		}
		count++;
		node = node->next;
	}
	
}

void LinkedLists::PrintList(ListNode* node)
{
	while (node != nullptr) //if node is not nullptr, cout data
	{
		std::cout << std::setw(5) << "| " << node->data << " |-->";
		node = node->next;
	}

	if (node == nullptr)
	{
		std::cout << "| NULL |" << std::endl;
	}

	std::cout << std::endl;
}

void LinkedLists::PrintListBackwards(ListNode* node)
{
	if (node != nullptr)
	{
		PrintListBackwards(node->next);
		std::cout << std::setw(5) << "| " << node->data << " |-->";
	}
}