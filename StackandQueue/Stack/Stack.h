#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
//如果用尾做栈顶，那么用双向链表更好，但是内存更大，建议单链表
//单链表就用头做栈顶，但是效率不如数组
// 
//typedef int STDDataType;
//#define MAX 100
//struct Stack
//{
//	STDDataType* a[MAX];
//	int top;
//};

typedef int STDDataType;
typedef struct Stack
{
	STDDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
//栈顶插入删除数据
void StackPush(Stack* ps, STDDataType x);
void StackPop(Stack* ps);
STDDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);





