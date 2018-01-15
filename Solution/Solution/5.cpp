#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
};

void printListReversily(ListNode *head)
{
	stack<ListNode *> pNodes;
	if (head == NULL)
		return;
	for (ListNode *cur = head; cur != NULL; cur = cur->m_pNext)
	{
		pNodes.push(cur);
	}
	while (!pNodes.empty())
	{
		cout << pNodes.top()->m_nKey << endl;
		pNodes.pop();
	}
}

void printListReversilyRecursily(ListNode *head)
{
	if (head == NULL)
		return;
	printListReversilyRecursily(head->m_pNext);
	cout << head->m_nKey << endl;
}

//int main()
//{
//	ListNode *head = NULL, *pCur = NULL;
//	int listnum = 0;
//	cin >> listnum;
//	while(listnum--)
//	{
//		ListNode *ptmp = new ListNode;
//		cin >> ptmp->m_nKey;
//		ptmp->m_pNext = NULL;
//		if (head == NULL)
//		{
//			pCur = head = ptmp;
//		}
//		else
//		{
//			pCur->m_pNext = ptmp;
//			pCur = pCur->m_pNext;
//		}
//		
//	}
//
//	printListReversily(head);
//	printListReversilyRecursily(head);
//	return 0;
//}