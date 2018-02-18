#pragma once
struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;
};

void PrintList(ListNode *pListHead);
ListNode* CreateList();