#include "BinaryTree.h"

using namespace std;

BinaryTreeNode* CreateMirror(BinaryTreeNode *src_root)
{
	if (!src_root)
		return NULL;

	BinaryTreeNode *mirror_root = new BinaryTreeNode;
	mirror_root->m_nValue = src_root->m_nValue;
	mirror_root->m_pLeft = CreateMirror(src_root->m_pRight);
	mirror_root->m_pRight = CreateMirror(src_root->m_pLeft);

	return mirror_root;
}

//int main()
//{
//	auto src_root = BuildBinaryTree();
//	PrintPreOder(src_root);
//	cout << endl;
//
//	auto mirrot_root = CreateMirror(src_root);
//	PrintPreOder(mirrot_root);
//	cout << endl;
//
//	return 0;
//}