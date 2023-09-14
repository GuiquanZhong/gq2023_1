#pragma once
#include<iostream>
using namespace std;
typedef int SQDataType;

//������һ������ͷ�ڵ�

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
SListNode * SListFind(SListNode* phead, SQDataType x);
//��posǰɾ��pos
void SListInsert(SListNode** pphead,SListNode* pos, SQDataType x);
//ɾ��posλ�õ�ֵ
void SListErase(SListNode** pphead,SListNode* pos);



