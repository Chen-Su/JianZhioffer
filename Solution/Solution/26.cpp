#include <iostream>
#include <map>

using namespace std;

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pRandom;
};

ComplexListNode* CopyComplexListBetter(ComplexListNode *pli_ori)
{
	if (!pli_ori)
		return NULL;

	auto pcur = pli_ori;
	// First time, insert new node in original list
	while (pcur)
	{
		auto pnext = pcur->m_pNext;
		pcur->m_pNext = new ComplexListNode;
		pcur->m_pNext->m_nValue = pcur->m_nValue;
		pcur = pcur->m_pNext;
		pcur->m_pNext = pnext;
		pcur->m_pRandom = NULL;
		pcur = pnext;
	}

	// Second time, link random node
	pcur = pli_ori;
	while (pcur)
	{
		pcur->m_pNext->m_pRandom = pcur->m_pRandom->m_pNext;
		pcur = pcur->m_pNext->m_pNext;
	}

	// Third time, split two list
	ComplexListNode dummy;
	ComplexListNode *pcur_cpy = &dummy;
	pcur = pli_ori;
	while (pcur)
	{
		pcur_cpy->m_pNext = pcur->m_pNext;
		pcur = pcur->m_pNext->m_pNext;
		pcur_cpy = pcur_cpy->m_pNext;
	}

	return dummy.m_pNext;
}

ComplexListNode* CopyComplexList(ComplexListNode *pli_ori)
{
	if (!pli_ori)
		return NULL;
	ComplexListNode dummy;
	map<ComplexListNode*, ComplexListNode*> complex_list_map;

	ComplexListNode *pcur_ori = pli_ori,*pcur_cpy = &dummy;
	// copy next order
	while (pcur_ori)
	{
		pcur_cpy->m_pNext = new ComplexListNode;
		pcur_cpy = pcur_cpy->m_pNext;
		pcur_cpy->m_nValue = pcur_ori->m_nValue;
		pcur_cpy->m_pNext = pcur_cpy->m_pRandom = NULL;
		complex_list_map[pcur_ori] = pcur_cpy;	// create map
		pcur_ori = pcur_ori->m_pNext;
	}

	// copy random order
	pcur_ori = pli_ori;
	pcur_cpy = dummy.m_pNext;
	while (pcur_ori)
	{
		pcur_cpy->m_pRandom = complex_list_map[pcur_ori->m_pRandom];
		pcur_ori = pcur_ori->m_pNext;
		pcur_cpy = pcur_cpy->m_pNext;
	}

	return dummy.m_pNext;
}

ComplexListNode* CreateComplexList()
{
	int n;
	cin >> n;
	ComplexListNode dummy;
	ComplexListNode *pcur = &dummy;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		pcur->m_pNext = new ComplexListNode;
		pcur = pcur->m_pNext;
		pcur->m_nValue = tmp;
		pcur->m_pNext = pcur->m_pRandom = NULL;
	}

	pcur = dummy.m_pNext;
	for (int i = 0; i < n; i++)
	{
		cout << "List Node " << i << "'s random node order(Start at 0) : ";
		int rand_order;
		cin >> rand_order;
		ComplexListNode *prand = dummy.m_pNext;
		while (rand_order--)
		{
			prand = prand->m_pNext;
		}
		pcur->m_pRandom = prand;
		cout << "Link done. Random Node is " << pcur->m_pRandom->m_nValue << endl;

		pcur = pcur->m_pNext;
	}

	return dummy.m_pNext;
}

void PrintComplexList(ComplexListNode *pli)
{
	int cnt = 0;
	while (pli)
	{
		cout << cnt << ":\t" << pli->m_nValue << "\t random point to :\t" << pli->m_pRandom->m_nValue << endl;
		cnt++;
		pli = pli->m_pNext;
	}
}

int main()
{
	auto pli_ori = CreateComplexList();
	PrintComplexList(pli_ori);
	//auto pli_cpy = CopyComplexList(pli_ori);
	auto pli_cpy = CopyComplexListBetter(pli_ori);
	PrintComplexList(pli_cpy);

	return 0;
}