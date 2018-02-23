/*
 * 没有测试，没有debug -.0
 */
#include <iostream>
#include <vector>

using namespace std;

// 普通的树节点
struct TreeNode
{
	int m_value;
	vector<TreeNode *> m_pchildren;
};

bool GetNodePath(TreeNode *root, TreeNode *pdst, vector<TreeNode *> &path)
{
	if (!root)
		return false;

	path.push_back(root);
	if (root == pdst)
	{
		return true;
	}
	for (auto it : root->m_pchildren)
	{
		if (GetNodePath(it, pdst, path))
			return true;
	}
	path.pop_back();
	return false;
}

TreeNode* FindCommonParent(vector<TreeNode *> &path_a, vector<TreeNode *> &path_b)
{
	TreeNode *pRes = NULL;
	for (int i = 0; i < path_a.size(); i++)
	{
		if (path_a[i] == path_b[i])
		{
			pRes = path_a[i];
		}
		else
			break;
	}

	return pRes;
}

TreeNode* FindCommonParentNode(TreeNode *root, TreeNode *pa, TreeNode *pb)
{
	if (!root || !pa || !pb)
		return NULL;

	vector<TreeNode *> path_a, path_b;
	if (!GetNodePath(root, pa, path_a))
	{
		cout << "Not found child node." << endl;
		return NULL;
	}
	if (!GetNodePath(root, pb, path_b))
	{
		cout << "Not found child node." << endl;
		return NULL;
	}

	auto pres = FindCommonParent(path_a, path_b);

	return pres;
}
