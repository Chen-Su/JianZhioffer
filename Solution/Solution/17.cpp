#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode* MergeAsscendList(ListNode *l1, ListNode *l2)
{
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	ListNode *merge_list = NULL, *pml = NULL;			
	ListNode *pl1 = l1, *pl2 = l2;

	if (pl1->m_nValue < pl2->m_nValue)
	{
		merge_list = pml = pl1;
		pl1 = pl1->m_pNext;
	}
	else
	{
		merge_list = pml = pl2;
		pl2 = pl2->m_pNext;
	}
	
	while (pl1 && pl2)
	{
		if (pl1->m_nValue < pl2->m_nValue)
		{
			pml->m_pNext = pl1;
			pl1 = pl1->m_pNext;
		}
		else
		{
			pml->m_pNext = pl2;
			pl2 = pl2->m_pNext;
		}
		pml = pml->m_pNext;
	}

	if (pl1)
	{
		pml->m_pNext = pl1;
	}
	
	if (pl2)
	{
		pml->m_pNext = pl2;
	}
	
	return merge_list;
}

void PrintList17(ListNode *pListHead)
{
	ListNode *pCurNode = pListHead;
	while (pCurNode)
	{
		cout << pCurNode->m_nValue << '\t';
		pCurNode = pCurNode->m_pNext;
	}
	cout << endl;
}

int main()
{
	ListNode *pListHead = NULL, *pCurNode = NULL;
	int n;
	cin >> n;
	bool isFirst = true;
	while (n--)
	{
		ListNode *ptmp = new ListNode;
		cin >> ptmp->m_nValue;
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

	PrintList17(pListHead);

	ListNode *pListHead2 = NULL;
	pCurNode = NULL;
	cin >> n;
	isFirst = true;
	while (n--)
	{
		ListNode *ptmp = new ListNode;
		cin >> ptmp->m_nValue;
		ptmp->m_pNext = NULL;
		if (isFirst)
		{
			pListHead2 = ptmp;
			pCurNode = ptmp;
			isFirst = false;
		}
		else
		{
			pCurNode->m_pNext = ptmp;
			pCurNode = pCurNode->m_pNext;
		}
	}

	PrintList17(pListHead2);

	auto merge_list = MergeAsscendList(pListHead, pListHead2);


	PrintList17(merge_list);


	return 0;
}