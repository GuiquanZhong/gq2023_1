#include"Slist.h"

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while(cur != NULL)
	{
		cout << cur->data;
		cur = cur->next;
	}
}


void SListPushBack(SListNode** plist, SQDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;

	if (*plist == NULL)
	{
		*plist = newnode;
	}
	else
	{
		SListNode* tail = *plist;
		while (tail->next != NULL) 
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
	
}

void SListPushFront(SListNode** plist, SQDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;


	newnode->next = *plist;
	*plist = newnode;
}

void SListPopFront(SListNode** plist)
{
	SListNode* next = (*plist)->next;//表示*是与plist结合的
	free(*plist);
	*plist = next;
}

void SListPopBack(SListNode** plist)
{
}
