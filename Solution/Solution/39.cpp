/*
 * isBalanced类似书上的解法，只是core函数的传入参数和返回参数颠倒了一下。
 */
#include "BinaryTree.h"
#include <iostream>
#include <algorithm>

using namespace std;

int DepthOfTree(BinaryTreeNode *root)
{
	if (!root)
		return 0;

	return max(DepthOfTree(root->m_pLeft), DepthOfTree(root->m_pRight)) + 1;
}

int IsBalancedCore(BinaryTreeNode *root, bool &res)
{
	if (!root)
		return 0;

	int len_left = IsBalancedCore(root->m_pLeft, res);
	int len_right = IsBalancedCore(root->m_pRight, res);
	if (abs(len_left - len_right) > 1)
		res = false;

	return max(len_left, len_right) + 1;
}

bool IsBalanced(BinaryTreeNode *root)
{
	if (!root)
		return true;
	bool res = true;
	IsBalancedCore(root, res);

	return res;
}


//int main()
//{
//	BinaryTreeNode *root = BuildBinaryTree();
//
//	cout << "Depth : " << DepthOfTree(root) << endl;
//
//	cout << IsBalanced(root) << endl;
//
//	return 0;
//}