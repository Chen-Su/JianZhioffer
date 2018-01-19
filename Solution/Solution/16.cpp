#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode* ReverseList(ListNode *pHead)
{
	if (pHead == NULL || pHead->m_pNext == NULL)
		return pHead;

	ListNode *pNewHead = NULL, *pAhead = NULL, *pBehind = NULL;
	pAhead = pHead->m_pNext;
	pBehind = pHead;
	while (pAhead)
	{
		pHead->m_pNext = pAhead->m_pNext;
		pAhead->m_pNext = pBehind;

		pBehind = pAhead;
		pAhead = pHead->m_pNext;
	}

	return pBehind;
}

ListNode* ReverseListText(ListNode *pHead)
{
	ListNode *pReverseHead = NULL;
	ListNode *pNode = pHead;
	ListNode *pPrev = NULL;

	while (pNode)
	{
		ListNode *pNext = pNode->m_pNext;

		if (!pNext)
			pReverseHead = pNode;
		pNode->m_pNext = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}

	return pReverseHead;
}

void PrintList16(ListNode *pListHead)
{
	ListNode *pCurNode = pListHead;
	while (pCurNode)
	{
		cout << pCurNode->m_nValue << '\t';
		pCurNode = pCurNode->m_pNext;
	}
	cout << endl;
}

//int main()
//{
//	ListNode *pListHead = NULL, *pCurNode = NULL;
//	int n;
//	cin >> n;
//	bool isFirst = true;
//	while (n--)
//	{
//		ListNode *ptmp = new ListNode;
//		cin >> ptmp->m_nValue;
//		ptmp->m_pNext = NULL;
//		if (isFirst)
//		{
//			pListHead = ptmp;
//			pCurNode = ptmp;
//			isFirst = false;
//		}
//		else
//		{
//			pCurNode->m_pNext = ptmp;
//			pCurNode = pCurNode->m_pNext;
//		}
//	}
//
//	PrintList16(pListHead);
//
//	auto pNewHead = ReverseList(pListHead);
//	//auto pNewHead = ReverseListText(pListHead);
//	
//	PrintList16(pNewHead);
//
//	return 0;
//}