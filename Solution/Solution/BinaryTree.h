#pragma once

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode* BuildBinaryTree();

void PrintPreOder(BinaryTreeNode *root);
