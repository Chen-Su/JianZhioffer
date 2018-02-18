#include "MyList.h"
#include <iostream>

using namespace std;

void PrintList(ListNode *pListHead)
{
	ListNode *pCurNode = pListHead;
	while (pCurNode)
	{
		cout << pCurNode->m_nKey << '\t';
		pCurNode = pCurNode->m_pNext;
	}
	cout << endl;
}

ListNode* CreateList()
{
	ListNode *pListHead = NULL, *pCurNode = NULL;
	int n;
	cin >> n;
	bool isFirst = true;
	while (n--)
	{
		ListNode *ptmp = new ListNode;
		cin >> ptmp->m_nKey;
		ptmp->m_pNext = NULL;
		if (isFirst)
		{
			pListHead = ptmp;
			pCurNode = ptmp;
			isFirst = false;
		}
		else
		{
			pCurNode->m_pNext = ptmp;
			pCurNode = pCurNode->m_pNext;
		}
	}

	return pListHead;
}

