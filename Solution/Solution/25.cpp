#include "BinaryTree.h"
#include <vector>

void FindPath(BinaryTreeNode *root, int expect_sum, vector<int> &path)
{
	if (!root)
		return;
	

	path.push_back(root->m_nValue);
	expect_sum -= root->m_nValue;

	if (expect_sum == 0 && !root->m_pLeft && !root->m_pRight)
	{
		// find one path
		for (auto val : path)
			cout << val << ' ';
		cout << endl;
		return;
	}

	FindPath(root->m_pLeft, expect_sum, path);
	FindPath(root->m_pRight, expect_sum, path);
	path.pop_back();
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