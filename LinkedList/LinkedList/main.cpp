#include <iostream>
#include "LinkedLists.h"


int main(int argc, char* argv[])
{
	LinkedLists* lists = new LinkedLists();

	ListNode* head = nullptr;

	lists->MakeNode(&head, 20);

	lists->InsertFirst(&head, 30);

	lists->InsertAfter(head, 40);

	lists->InsertAfter(head, 10);

	lists->PrintList(head);

	lists->GetNode(head, 1);
	

	std::cout << "delete list" << std::endl;

	
	lists->DeletefromPosition(head, 1);

	lists->DeleteAfter(head->next);


	lists->PrintList(head);
}