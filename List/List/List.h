#pragma once
//带头双向循环列表
#include<iostream>
#include<assert.h>
using namespace std;
typedef int LQDataType;
struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LQDataType data;
};

ListNode* ListInit();
void ListDestory(ListNode* phead);
void ListPushBack(ListNode* phead, LQDataType x);
void ListPushFront(ListNode* phead, LQDataType x);
void ListPopFront(ListNode* phead);
void ListPopBack(ListNode* phead);
void ListPrint(ListNode* phead);
ListNode* ListFind(ListNode* phead, LQDataType x);
void ListInsert(ListNode* pos, LQDataType x);
void ListErase(ListNode* pos);