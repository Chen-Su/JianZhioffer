/*
 * TransBST2List 是自己写的方法，后序遍历，先转好根节点的左子树和右子树，并返回两个子树的头结点和尾结点
 * 然后根节点左指针链接左子树的尾结点，右指针链接右子树的头结点
 * TransText 是书上的方法，增加了pphead参数，就不用在最后往前遍历寻找头结点，但需要保证先把*pphead初始化为NULL
 */

#include "BinaryTree.h"

using namespace std;

void TransBST2List(BinaryTreeNode *proot, BinaryTreeNode **pphead, BinaryTreeNode **pptail)
{
	*pphead = *pptail = proot;

	if (!proot)
	{
		*pphead = *pptail = NULL;
		return;
	}

	BinaryTreeNode *phead_left, *ptail_left, *phead_right, *ptail_right;
	phead_left = phead_right = ptail_left = ptail_right = NULL;

	TransBST2List(proot->m_pLeft, &phead_left, &ptail_left);
	TransBST2List(proot->m_pRight, &phead_right, &ptail_right);

	if (ptail_left)
	{
		proot->m_pLeft = ptail_left;
		ptail_left->m_pRight = proot;
	}
	if (phead_right)
	{
		proot->m_pRight = phead_right;
		phead_right->m_pLeft = proot;
	}
	if(phead_left)
		*pphead = phead_left;
	if(ptail_right)
		*pptail = ptail_right;
}

void TransText(BinaryTreeNode *proot, BinaryTreeNode **pphead, BinaryTreeNode **pplast_node)
{
	if (!proot)
		return;
	
	TransText(proot->m_pLeft, pphead, pplast_node);
	if (*pphead == NULL)
		*pphead = proot; // First node.
	proot->m_pLeft = *pplast_node;
	if (*pplast_node)
	{
		(*pplast_node)->m_pRight = proot;
	}

	*pplast_node = proot;
	TransText(proot->m_pRight, pphead, pplast_node);
}

void PrintBiOrderList(BinaryTreeNode *phead, BinaryTreeNode *ptail)
{
	while (phead)
	{
		cout << phead->m_nValue << ' ';
		phead = phead->m_pRight;
	}

	while (ptail)
	{
		cout << ptail->m_nValue << ' ';
		ptail = ptail->m_pLeft;
	}
}

//int main()
//{
//	BinaryTreeNode *proot = BuildBinaryTree();
//	BinaryTreeNode *phead, *ptail;
//	phead = ptail = NULL;
//	//TransBST2List(proot, &phead, &ptail);
//	TransText(proot, &phead, &ptail);
//	PrintBiOrderList(phead, ptail);
//
//	return 0;
//}