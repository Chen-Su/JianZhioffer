#include <vector>

using namespace std;

struct MyStack
{
	vector<int> data;
	vector<int> minYet;		// ���浽��ǰΪֹ����Сֵ

	bool push(int val);
	bool pop();
	int min();
	int top();
};