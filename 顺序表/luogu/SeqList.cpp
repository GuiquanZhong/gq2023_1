#include"SeqList.h"
using namespace std;


//void SeqListInit(SL *s1)
//{
//	memset(s1->a, 0, sizeof(SQDataType) * N);
//	s1->size = 0;
//}
//
//void SeqListPushBack(SL* s1, SQDataType x)
//{
//	if (s1->size >= N)
//	{
//		printf("SeqList if Full\n");
//	}
//	s1->a[s1->size] = x;
//	s1->size++;
//}
//

////动态结构
void SeqListInit(SL *s1)
{
	s1->a = NULL;
	s1->size = 0;
	s1->capacity = 0;
}

//尾插
void SeqListPushBack(SL* s1, SQDataType x)
{
	//满了就要扩容
	if (s1->size == s1->capacity)
	{
		int newcapacity = s1->capacity == 0 ? 4 : s1->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(s1->a, s1->capacity * 2 * sizeof(SQDataType));
		if (tmp == NULL)
		{  
			cout << "realloc fail" << endl;
			exit(-1);
		}
		else
		{
			s1->a = tmp;
			s1->capacity *= 2;
		}
	}
	s1->a[s1->size] = x;
	s1->size++;
}
//尾删
void SeqListPopBack(SL* s1) {
	assert(s1->size > 0);
	s1->size--;
}

//头删
void SeqListPopFront(SL* s1)
{
	//从前往后开始挪
	int start = 1;
	while (start < s1->size)
	{
		s1->a[start - 1] = s1->a[start];
		start++;
	}
	s1->size--;
}

//任意位置插入数据
void SeqListInsert(SL* s1, int pos, SQDataType x)
{
	assert(s1->size > pos);
	if (s1->size=1 >= s1->capacity)
	{
		SQDataType* tmp = (SQDataType*)realloc(s1->a,s1->capacity * 2 * sizeof(SQDataType));
	}
	SQDataType end = s1->size - 1;
	while (end >= pos)
	{
		s1->a[end + 1] = s1->a[end];
		end--;
	}
	s1->a[pos] = x;
	s1->size++;

}

//删除任意位置
void SeqListErase(SL* s1, int pos)
{
	assert(s1->size > pos);//判断条件
	while (s1->size - 1 > pos)  //往前挪
	{
		s1->a[pos] = s1->a[pos + 1];
		pos++;
	}
	s1->size++;

}



//打印
void SeqListPrint(SL* s1)
{
	for (int i = 0; i < s1->size; i++)
	{
		cout << s1->a[i];
	}
	cout << endl;
}
