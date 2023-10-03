#include"Sort.h"

//���趼������

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// ֱ�Ӳ�������
//   x| a,b,c,d   �Ȱ�a���룬�ٰ�b����...
//1,3,2,7,8,5,4,5,6,11   1 2 3
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
		 	else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	//[0, end]  ��end+1���룬��{0��end+1]����
	

}


//ϣ������  O(N*logN)
void ShellSort(int* arr, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 2; //��֤���һ�ζ���1
		// gap>1 ����Ԥ����   �ӽ�����
		//gap==1����ֱ�Ӳ�������


		//�Ѽ��Ϊgap�Ķ�������ͬʱ����
	//end = 1, 2, 3 , 4...����ϣ��
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}

			}
			arr[end + gap] = tmp;
		}
	}
	
}






//�ѵ�����ṹ�Ǹ�����
//ǰ�᣺���Ҷ���С��
void ADjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		//1��ѡ�����Һ����н�С���Ǹ�
		if (child + 1 < n && a[child + 1] > a[child])    //��ѸĴ��ں�
		{
			child += 1;
		}
		if (a[child] > a[parent])   //��ѸĴ��ں�
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}


//������ �����Ҷ�
void HeapSort(int* a, int n)
{
	//������������ɴ��
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		ADjustDwon(a, n, i);
	}
//������;
//����ѣ���һ�������һ������������������������
//ǰn-1�������µ�����ѡ���δ����
//�ٸ������ڶ�����λ�ý���   O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		swap(a[0], a[end]);
		ADjustDwon(a, end, 0);
		end--;
	}

}




//ֱ��ѡ������
//O(N*N)
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		swap(a[begin], a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(a[maxi], a[end]);
		++begin;
		--end;
	}


}

//ð������  O(N*N)
//1,3,2,7,8,5,4,5,6,11
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; j++)
	{
		int exchange = 0;
		for (int i = 1; i < n-j; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i - 1], a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}


}










int main()
{
	int a[] = { 1,3,2,7,8,5,4,5,6,11 };
	//ShellSort(a, 10);
	BubbleSort(a, 10);
	Print(a,10);
	return 0;
}