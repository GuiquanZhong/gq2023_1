#include"Slist.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while(cur != NULL)
	{
		cout << cur->data;
		cur = cur->next;
	}
}


void SListPushBack(SListNode** pphead, SQDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next != NULL) 
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
	
}

void SListPushFront(SListNode** pphead, SQDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;


	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopFront(SListNode** pphead)
{
	SListNode* next = (*pphead)->next;//表示*是与plist结合的
	free(*pphead);
	*pphead = next;
}

void SListPopBack(SListNode** pphead)
{
	SListNode* prev = NULL;
	SListNode* tail = *pphead;
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	while (tail->next!=NULL) 
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	prev->next = NULL;

}

void SListInsert(SListNode** pphead, SListNode* pos, SQDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = x;
	newnode->next = NULL;
	SListNode* prev = *pphead;
	if (prev = pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListErase(SListNode** pphead, SListNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SListNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

SListNode * SListFind(SListNode* phead, SQDataType x)
{
	SListNode* cur = phead;
	
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
