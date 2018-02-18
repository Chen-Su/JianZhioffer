/*
 * �����������һ�ַ����� �ȱ�����������õ����ǵĳ��ȣ�
 * �ó������ָ���ƶ����ɲ������������ʣ�೤����ȣ�
 * ��ͬʱ������������
 * �����ͼ����˸���ջ���ڴ����ġ�
 */
#include <iostream>
#include <stack>
#include "MyList.h"

using namespace std;


ListNode* FindCommonNode(ListNode *l1, ListNode *l2)
{
	if (!l1 || !l2)
		return NULL;

	stack<ListNode *> l1_nodes, l2_nodes;

	ListNode *pcur = l1;
	while (pcur)
	{
		l1_nodes.push(pcur);
		pcur = pcur->m_pNext;
	}
	pcur = l2;
	while (pcur)
	{
		l2_nodes.push(pcur);
		pcur = pcur->m_pNext;
	}

	while (!l1_nodes.empty() && !l2_nodes.empty())
	{
		if (l1_nodes.top() == l2_nodes.top())
			pcur = l1_nodes.top();
		else
			break;
		l1_nodes.pop();
		l2_nodes.pop();
	}

	return pcur;
}

//int main()
//{
//	ListNode *l1 = CreateList();
//	ListNode *l2 = CreateList();
//
//	int n;
//	cin >> n; // Put l2 link behind l1's nth nodeppp
//	ListNode *pcur = l1;
//	while (--n)
//		pcur = pcur->m_pNext;
//
//	ListNode *l2_tail = l2;
//	while (l2_tail->m_pNext)
//	{
//		l2_tail = l2_tail->m_pNext;
//	}
//	l2_tail->m_pNext = pcur->m_pNext;
//
//	PrintList(l1);
//	PrintList(l2);
//
//	ListNode *pcommon = FindCommonNode(l1, l2);
//
//	PrintList(pcommon);
//
//	return 0;
//}
