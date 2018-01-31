#include "BinaryTree.h"
#include <vector>

void FindPath(BinaryTreeNode *root, int expect_sum, vector<int> path)
{
	if (!root)
		return;
	if (root->m_nValue > expect_sum)
		return;
	
	path.push_back(root->m_nValue);
	if (root->m_nValue == expect_sum)
	{
		// find one path
		for (auto val : path)
			cout << val << ' ';
		cout << endl;
		return;
	}
	
		FindPath(root->m_pLeft, expect_sum - root->m_nValue, path);
		FindPath(root->m_pRight, expect_sum - root->m_nValue, path);
	
}

//int main()
//{
//	auto root = BuildBinaryTree();
//	int sum = 0;
//	cin >> sum;
//	vector<int> path;
//	FindPath(root, sum, path);
//
//	return 0;
//}