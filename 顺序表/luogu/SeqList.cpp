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

////��̬�ṹ
void SeqListInit(SL *s1)
{
	s1->a = NULL;
	s1->size = 0;
	s1->capacity = 0;
}

//β��
void SeqListPushBack(SL* s1, SQDataType x)
{
	//���˾�Ҫ����
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
//βɾ
void SeqListPopBack(SL* s1) {
	assert(s1->size > 0);
	s1->size--;
}

//ͷɾ
void SeqListPopFront(SL* s1)
{
	//��ǰ����ʼŲ
	int start = 1;
	while (start < s1->size)
	{
		s1->a[start - 1] = s1->a[start];
		start++;
	}
	s1->size--;
}

//����λ�ò�������
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

//ɾ������λ��
void SeqListErase(SL* s1, int pos)
{
	assert(s1->size > pos);//�ж�����
	while (s1->size - 1 > pos)  //��ǰŲ
	{
		s1->a[pos] = s1->a[pos + 1];
		pos++;
	}
	s1->size++;

}



//��ӡ
void SeqListPrint(SL* s1)
{
	for (int i = 0; i < s1->size; i++)
	{
		cout << s1->a[i];
	}
	cout << endl;
}
