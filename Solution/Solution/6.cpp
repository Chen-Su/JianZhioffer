#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

BinaryTreeNode* RebuildBT(vector<int> preorder, int prebegin, int preend, vector<int> inorder, int inbegin, int inend, BinaryTreeNode *root)
{
	if (prebegin > preend)
		return NULL;
	root = new BinaryTreeNode;
	root->m_nValue = preorder[prebegin];
	root->left = root->right = NULL;
	int pivot = 0;
	for (; inbegin + pivot <= inend && inorder[inbegin + pivot] != preorder[prebegin]; pivot++)
	{

	}
	if (inbegin + pivot > inend)
	{
		cerr << "input order isn't correct.";
		exit(-1);
	}
	root->left = RebuildBT(preorder, prebegin + 1, prebegin + pivot, inorder, inbegin, inbegin + pivot, root->left);
	root->right = RebuildBT(preorder, prebegin + pivot + 1, preend, inorder, inbegin + pivot + 2, inend, root->right);

	return root;
}

void preOrderTraverse(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	cout << root->m_nValue << endl;
	preOrderTraverse(root->left);
	preOrderTraverse(root->right);
}

int main()
{
	int nodenum = 0;
	cout << "Input node number : ";
	cin >> nodenum;
	vector<int> preorder, inorder;
	cout << "Input PreOder : ";
	for (int i = 0; i < nodenum; i++)
	{
		int tmp;
		cin >> tmp;
		preorder.push_back(tmp);
	}
	cout << "Input InOder : ";
	for (int i = 0; i < nodenum; i++)
	{
		int tmp;
		cin >> tmp;
		inorder.push_back(tmp);
	}
	BinaryTreeNode *root = NULL;
	root = RebuildBT(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, root);
	preOrderTraverse(root);

	return 0;
}