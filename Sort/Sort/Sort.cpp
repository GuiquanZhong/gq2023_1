#include"Sort.h"

//假设都用升序

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// 直接插入排序
//   x| a,b,c,d   先把a插入，再把b插入...
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
	//[0, end]  把end+1插入，让{0，end+1]有序
	

}


//希尔排序  O(N*logN)
void ShellSort(int* arr, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 2; //保证最后一次都是1
		// gap>1 都是预排序   接近有序
		//gap==1就是直接插入排序


		//把间隔为gap的多组数据同时插入
	//end = 1, 2, 3 , 4...分组希尔
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






//堆的物理结构是个数组
//前提：左右都是小堆
void ADjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		//1、选出左右孩子中较小的那个
		if (child + 1 < n && a[child + 1] > a[child])    //大堆改大于号
		{
			child += 1;
		}
		if (a[child] > a[parent])   //大堆改大于号
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


//堆排序 利用找顶
void HeapSort(int* a, int n)
{
	//把数组的数建成大堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		ADjustDwon(a, n, i);
	}
//堆排序;
//建大堆，第一个和最后一个交换，把他不看做堆里面
//前n-1个数向下调整，选出次大的数
//再跟倒数第二个个位置交换   O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		swap(a[0], a[end]);
		ADjustDwon(a, end, 0);
		end--;
	}

}




//直接选择排序
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

//冒泡排序  O(N*N)
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