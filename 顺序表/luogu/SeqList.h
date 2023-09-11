#pragma once
#pragma once
#include<string>
#include<iostream>
#define N 100
#include<assert.h>
typedef int SQDataType;
typedef struct SeqList
{
	SQDataType* a;
	int size;//有效数据个数
	int capacity;//容量
}SL;

void SeqListInit(SL *s1);
void SeqListPushBack(SL *s1, SQDataType x);
void SeqListPopBack(SL* s1);
void SeqListPopFront(SL* s1);
void SeqListInsert(SL* s1,int pos, SQDataType x);
void SeqListErase(SL* s1,int pos);
void SeqListPrint(SL* s1);


