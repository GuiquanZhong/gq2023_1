#pragma once
#include<iostream>
using namespace std;
typedef int SQDataType;

//可设置一个虚拟头节点

struct SListNode
{
	SQDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLTNode;
//不会改变链表的头指针，传一级指针
void SListPrint(SListNode* phead);
//会改变链表的头指针，传二级指针
void SListPushBack(SListNode** pphead, SQDataType x);
void SListPushFront(SListNode** pphead, SQDataType x);
void SListPopFront(SListNode** pphead);
void SListPopBack(SListNode** pphead);
SListNode * SListFind(SListNode* phead, SQDataType x);
//在pos前删除pos
void SListInsert(SListNode** pphead,SListNode* pos, SQDataType x);
//删除pos位置的值
void SListErase(SListNode** pphead,SListNode* pos);



