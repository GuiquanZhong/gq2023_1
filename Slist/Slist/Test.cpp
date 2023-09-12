#include"Slist.h"

void TestSList1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 1); 
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushFront(&plist, 0);
	SListPrint(plist);
	cout << endl;
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
}

int main()
{
	TestSList1();

	return 0;
}