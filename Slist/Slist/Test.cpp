#include"Slist.h"

void TestSList1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1); 
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);

	SListNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 999);
	}

	SListPushBack(&plist, 4);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 7);
	SListPushFront(&plist, 0);
	SListPrint(plist);
	cout << endl;
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopBack(&plist);
	SListNode* x = SListFind(plist, 6);
	if (x)
	{
		SListErase(&plist, x);
	}
	SListPrint(plist);
}

int main()
{
	TestSList1();

	return 0;
}