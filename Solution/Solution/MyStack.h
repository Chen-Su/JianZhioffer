#include <vector>

using namespace std;

struct MyStack
{
	vector<int> data;
	vector<int> minYet;		// 保存到当前为止的最小值

	bool push(int val);
	bool pop();
	int min();
	int top();
};