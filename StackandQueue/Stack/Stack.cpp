#include"Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = (STDDataType*)malloc(sizeof(STDDataType) * 4);
	if (ps->a == NULL)
	{
		printf("realloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
//ջ������ɾ������
void StackPush(Stack* ps, STDDataType x)
{
	assert(ps);
	//��������
	if (ps->top == ps->capacity)
	{
		STDDataType* tmp = (STDDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	//���ջ���ˣ�����pop��ֱ����ֹ
	assert(ps->top > 0);
	ps->top--;
}
STDDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top-1];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}