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
void SListPrint(SListNode* plist);
//��ı������ͷָ�룬������ָ��
void SListPushBack(SListNode** plist, SQDataType x);
void SListPushFront(SListNode** plist, SQDataType x);
void SListPopFront(SListNode** plist);
void SListPopBack(SListNode** plist);
void SListInsert(SListNode** plist, SQDataType x);
void SListErase(SListNode** plist, SQDataType x);


