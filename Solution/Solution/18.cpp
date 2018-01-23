#include "BinaryTree.h"

using namespace std;


bool isBinA(BinaryTreeNode *rootA, BinaryTreeNode *rootB)
{
	if (!rootB)
		return true;
	if (!rootA)
		return false;

	if (rootA->m_nValue != rootB->m_nValue)
		return false;
	return isBinA(rootA->m_pLeft, rootB->m_pLeft)
		&& isBinA(rootA->m_pRight, rootB->m_pRight);
}

bool PreOrderSearch(BinaryTreeNode *root, BinaryTreeNode *desroot)
{
	if (!root || !desroot)
		return false;
	
	if (root->m_nValue == desroot->m_nValue)
		if (isBinA(root, desroot))
			return true;

	return PreOrderSearch(root->m_pLeft, desroot) ||
		PreOrderSearch(root->m_pRight, desroot);
}


//
//int main()
//{
//	auto rootA = BuildBinaryTree();
//	auto rootB = BuildBinaryTree();
//
//	PrintPreOder(rootA);
//	cout << endl;
//
//	PrintPreOder(rootB);
//	cout << endl;
//
//	cout << PreOrderSearch(rootA, rootB) << endl;
//
//	return 0;
//}