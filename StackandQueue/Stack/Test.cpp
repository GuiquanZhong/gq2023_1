#include"Stack.h"
#include"Queue.h"

void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 99);
	StackPush(&st, 5);
	StackPop(&st);
	StackPush(&st, 6);

	while (!StackEmpty(&st))
	{
		cout << StackTop(&st);
		StackPop(&st);
	}
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
}

int main()
{
	//TestStack

	return 0;
}