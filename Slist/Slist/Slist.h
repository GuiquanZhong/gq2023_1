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
//����ı������ͷָ�룬��һ��ָ��
void SListPrint(SListNode* phead);
//��ı������ͷָ�룬������ָ��
void SListPushBack(SListNode** pphead, SQDataType x);
void SListPushFront(SListNode** pphead, SQDataType x);
void SListPopFront(SListNode** pphead);
void SListPopBack(SListNode** pphead);
void SListInsert(SListNode** pphead, SQDataType x);
void SListErase(SListNode** pphead, SQDataType x);


