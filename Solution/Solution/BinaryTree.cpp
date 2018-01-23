#include "BinaryTree.h"

BinaryTreeNode* BuildBinaryTree()
{
	int val = 0;
	cin >> val;
	if (val == -1)
		return NULL;

	auto root = new BinaryTreeNode;
	root->m_nValue = val;
	root->m_pLeft = BuildBinaryTree();
	root->m_pRight = BuildBinaryTree();

	return root;
}

void PrintPreOder(BinaryTreeNode *root)
{
	if (root)
	{
		cout << root->m_nValue << '\t';
		PrintPreOder(root->m_pLeft);
		PrintPreOder(root->m_pRight);
	}
}