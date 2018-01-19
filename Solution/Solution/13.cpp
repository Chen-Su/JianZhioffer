/*
 * O(1)时间删除单向链表中的非尾节点。
 * 很好的思路。
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
	if (pListHead == NULL || *pListHead == NULL || pToBeDeleted == NULL)
		return;

	if (*pListHead == pToBeDeleted && pToBeDeleted->m_pNext == NULL)
	// Ö»ÓÐÒ»¸ö½ÚµãµÄÇé¿ö
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
		return;
	}

	// ÏÈ¿¼ÂÇÉ¾³ý×îºóÒ»¸ö½ÚµãµÄÇé¿ö
	if (pToBeDeleted->m_pNext == NULL)
	{
		ListNode *pPreNode = *pListHead;
		while (pPreNode->m_pNext != pToBeDeleted)
			pPreNode = pPreNode->m_pNext;
		pPreNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
	else
	{
		// swap and delete
		ListNode *ptmp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = ptmp->m_nValue;
		pToBeDeleted->m_pNext = ptmp->m_pNext;
		delete ptmp;
		ptmp = NULL;
	}

	
}

void PrintList(ListNode **pListHead)
{
	if (pListHead == NULL)
		return;
	ListNode *ptmpNode = *pListHead;
	while (ptmpNode)
	{
		cout << ptmpNode->m_nValue << '\t';
		ptmpNode = ptmpNode->m_pNext;
	}
	cout << endl;
}

//int main()
//{
//	int n;
//	cout << "Input node num : ";
//	cin >> n;
//
//	ListNode **pListHead = NULL, *pHeadNode = NULL, *pcurNode = NULL;
//	vector<ListNode *> pListNodes;
//	
//	bool isFirst = true;
//	while (n--)
//	{
//		ListNode *ptmpNode = new ListNode;
//		cin >> ptmpNode->m_nValue;
//		ptmpNode->m_pNext = NULL;
//		if (isFirst)
//		{
//			pHeadNode = ptmpNode;
//			pListHead = &pHeadNode;
//			pcurNode = ptmpNode;
//			isFirst = false;
//		}
//		else
//		{
//			pcurNode->m_pNext = ptmpNode;
//			pcurNode = ptmpNode;
//		}
//		pListNodes.push_back(pcurNode);
//	}
//
//	PrintList(pListHead);
//
//
//	while (true)
//	{
//		int deleteN;
//		cout << "Input element order you wanna delete : ";
//		cin >> deleteN;
//		DeleteNode(pListHead, pListNodes[deleteN]);
//		PrintList(pListHead);
//	}
//
//
//	return 0;
//}