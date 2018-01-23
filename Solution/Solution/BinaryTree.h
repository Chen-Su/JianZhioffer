#pragma once

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

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