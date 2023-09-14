#include"List.h"

void TestList1()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListPushFront(plist, 0);
	ListPrint(plist);
	ListPopFront(plist);
	ListPopBack(plist);
	ListPushFront(plist, 9);
	ListPrint(plist);
}
void TestList2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);

	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListNode* pos = ListFind(plist, 3);
	if (pos)
	{
		pos->data *= 10;
		cout << "�ҵ��ˣ���ַΪ��" << pos << ", ���ҽڵ��ֵ * 10" << endl;
		ListInsert(pos, 89);
		
	}
	else
	{ 
		cout << "û�ҵ�;" << endl;
	}
	ListPrint(plist);
	ListErase(pos);
	ListPrint(plist);
	ListPrint(plist);
	ListDestory(plist);
}

int main()
{
	TestList1();
	TestList2();
	return 0;
}