#include <iostream>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

BinaryTreeNode* ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder)
{
	// 前序遍历序列的第一个数字是根节点的值
	int rootValue = startPreorder[0];
	BinaryTreeNode *root = new BinaryTreeNode;
	root->m_nValue = rootValue;
	root->left = root->right = NULL;

	if (startPreorder == endPreorder)
	// 必要吗？
	// 书上的代码是以叶子节点作为递归出口
	// 而我的代码是以叶子的空孩子为递归出口
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	// 在中序遍历中找到根节点的值
	int *rootInorder = startInorder;
	while (rootInorder < endInorder && rootValue != *rootInorder)
		// 指针++与比较，个人很少使用
		++rootInorder;

	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	int leftLength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
		root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	if (leftLength < endPreorder - startPreorder)
	{
		root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

BinaryTreeNode* Construct(int *preorder, int *inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return ConstructCore(preorder, preorder + length - 1,
		inorder, inorder + length - 1);
}

BinaryTreeNode* RebuildBT(vector<int> preorder, int prebegin, int preend, vector<int> inorder, int inbegin, int inend)
{
	if (prebegin > preend)
		return NULL;

	BinaryTreeNode *root = new BinaryTreeNode;
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
	root->left = RebuildBT(preorder, prebegin + 1, prebegin + pivot, inorder, inbegin, inbegin + pivot - 1);
	root->right = RebuildBT(preorder, prebegin + pivot + 1, preend, inorder, inbegin + pivot + 1, inend);

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

void inOrderTraverse(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	
	inOrderTraverse(root->left);
	cout << root->m_nValue << endl;
	inOrderTraverse(root->right);
}

void postOrderTraverse(BinaryTreeNode *root)
{
	if (root == NULL)
		return;

	postOrderTraverse(root->left);
	postOrderTraverse(root->right);
	cout << root->m_nValue << endl;
}

//int main()
//{
//	int nodenum = 0;
//	cout << "Input node number : ";
//	cin >> nodenum;
//	vector<int> preorder, inorder;
//	cout << "Input PreOder : ";
//	for (int i = 0; i < nodenum; i++)
//	{
//		int tmp;
//		cin >> tmp;
//		preorder.push_back(tmp);
//	}
//	cout << "Input InOder : ";
//	for (int i = 0; i < nodenum; i++)
//	{
//		int tmp;
//		cin >> tmp;
//		inorder.push_back(tmp);
//	}
//	BinaryTreeNode *root = NULL;
//	root = RebuildBT(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
//	preOrderTraverse(root);
//	inOrderTraverse(root);
//	postOrderTraverse(root);
//
//	return 0;
//}