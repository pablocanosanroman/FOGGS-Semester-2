#pragma once

#include "structs.h"
#include <iostream>
#include <iomanip>

class LinkedLists
{
private:
	ListNode* head = nullptr;

public:
	LinkedLists();
	~LinkedLists();

	ListNode* MakeNode(ListNode** head, int d);
	ListNode* InsertFirst(ListNode** head, int d);
	void InsertAfter(ListNode* lastNode, int d);
	void DeleteList(ListNode** node);
	void DeleteAfter(ListNode* node);
	void DeletefromPosition(ListNode* node, int pos);
	ListNode* GetNode(ListNode* node, int pos);
	ListNode* Find(ListNode* node, int val);
	void PrintList(ListNode* node);
};

