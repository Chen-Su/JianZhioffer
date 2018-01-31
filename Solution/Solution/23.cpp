#include "BinaryTree.h"
#include <queue>

using namespace std;

void PrintbyLevel(BinaryTreeNode *root)
{
	if (!root)
		return;

	auto pcur_node = root;
	queue<BinaryTreeNode *> unfinished_nodes;
	unfinished_nodes.push(root);

	while (!unfinished_nodes.empty())
	{
		pcur_node = unfinished_nodes.front();
		unfinished_nodes.pop();
		
		cout << pcur_node->m_nValue << endl;

		if (pcur_node->m_pLeft)
			unfinished_nodes.push(pcur_node->m_pLeft);
		if (pcur_node->m_pRight)
			unfinished_nodes.push(pcur_node->m_pRight);
	}
}

int main()
{
	auto root = BuildBinaryTree();

	PrintbyLevel(root);

}