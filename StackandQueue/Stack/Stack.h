#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
//�����β��ջ������ô��˫��������ã������ڴ���󣬽��鵥����
//���������ͷ��ջ��������Ч�ʲ�������
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
//ջ������ɾ������
void StackPush(Stack* ps, STDDataType x);
void StackPop(Stack* ps);
STDDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);





