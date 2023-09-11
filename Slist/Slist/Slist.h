#pragma once
#include<iostream>
using namespace std;
typedef int SQDataType;
struct SListNode
{
	SQDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLTNode;
//不会改变链表的头指针，传一级指针
void SListPrint(SListNode* plist);
//会改变链表的头指针，传二级指针
void SListPushBack(SListNode** plist, SQDataType x);
void SListPushFront(SListNode** plist, SQDataType x);
void SListPopFront(SListNode** plist);
void SListPopBack(SListNode** plist);
void SListInsert(SListNode** plist, SQDataType x);
void SListErase(SListNode** plist, SQDataType x);


