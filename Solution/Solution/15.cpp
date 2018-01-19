#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

ListNode* GetKthLastNode(ListNode *pListHead, int k)
{
	if (!pListHead)
		throw exception("List is NULL");
	if (k <= 0)
		throw exception("k is invalid");

	ListNode *pNode1 = NULL, *pNode2 = NULL;

	pNode1 = pNode2 = pListHead;
	while (k > 1 && pNode1)
	{
		pNode1 = pNode1->m_pNext;
		--k;
	}
	if (k > 1 || !pNode1)
		// ע����pNode1�Ƿ�ΪNULL
		// ��List����Ϊ5, k�ĺϷ�ֵӦ����[1,5]
		// ����kΪ6ʱ������whileѭ��֮��kҲ����1��pNode1�ƶ���β�ڵ����һ�ڵ㣬��NULL
		throw exception("List's size is less than %d", k);
	
	while (pNode1->m_pNext)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNode2;
}

void PrintList(ListNode *pListHead)
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
//	PrintList(pListHead);
//
//	while (true)
//	{
//		int k;
//		cin >> k;
//		try {
//			ListNode *pNode = GetKthLastNode(pListHead, k);
//			cout << pNode->m_nValue << endl;
//		}
//		catch(exception &e)
//		{
//			cout << e.what() << endl;
//		}
//	}
//
//	return 0;
//}