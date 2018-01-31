#include "BinaryTree.h"
#include <vector>
#include <iterator>

bool isPostOrder(vector<int> &order, vector<int>::iterator &o_begin, vector<int>::iterator &o_end)
{
	if (order.empty() || distance(o_begin, o_end) <= 2)
		return true;

	auto o_cur = o_begin, o_pivot = o_begin;
	int root_val = *(o_end - 1);	// 最后一个元素，一定是root
	while (o_cur != o_end && *o_cur < root_val)
	{
		++o_cur;
		++o_pivot;
	}
	while (o_cur != o_end - 1)
	{
		// 检查右子树
		if (*o_cur < root_val)
			return false;
		++o_cur;
	}
	return isPostOrder(order, o_begin, o_pivot)
		&& isPostOrder(order, o_pivot, o_end-1);
}

//int main()
//{
//	vector<int> order;
//	int n = 0;
//	while (true)
//	{
//		cin >> n;
//		while (n--)
//		{
//			int tmp;
//			cin >> tmp;
//			order.push_back(tmp);
//		}
//		cout << isPostOrder(order, begin(order), end(order)) << endl;
//		order.clear();
//	}
//	
//	return 0;
//}