#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

struct Queue
{
	QNode* head;
	QNode* tail;
};

void QueueInit(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueueDestory(Queue* pq);
void QueuePop(Queue* pq);
QDataType QueueBack(Queue* pq);
QDataType QueueFront(Queue* pq);
int QueueSIze(Queue* pq);
bool QueueEmpty(Queue* pq);