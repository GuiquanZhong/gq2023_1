#include"List.h"

ListNode* BuyListNode(LQDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
} 
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		cout << cur->data<<" ";
		cur=cur->next;
	}
	cout << endl;
}
ListNode* ListFind(ListNode* phead, LQDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur->next != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LQDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	pos->prev = newnode;
	newnode->next = pos;
	
}
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur->next != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
void ListPushBack(ListNode* phead, LQDataType x)
{

	assert(phead);//phead为空的时候报错

	//不论是不是空链表
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);

	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	tail->next = newnode;
}

void ListPushFront(ListNode* phead, LQDataType x)
{
	assert(phead);
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	newnode->next = first;
	newnode->prev = phead;
	phead->next = newnode;
	first->prev = newnode;
}

void ListPopFront(ListNode* phead)
{
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = first->next;
	second->prev = phead;
	free(first);
	first = NULL;
}

void ListPopBack(ListNode* phead)
{
	assert(phead->prev != phead);
	ListNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	tail = NULL;
}
