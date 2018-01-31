#include <stack>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool isRightOrder(vector<int> &push_order, vector<int> &pop_order)
{
	set<int> in_stack;
	stack<int> simulate_stack;
	int index_pop, index_push;
	index_pop = index_push = 0;
	while (true)
	{
		if (index_pop == pop_order.size())
			return true;

		
		if (index_push < push_order.size() && push_order[index_push] == pop_order[index_pop])
		// skip same order elem
		{
			++index_pop;
			++index_push;
		}
		else if (in_stack.count(pop_order[index_pop]) > 0)
		// pop if elem in in_stack
		{
			if (simulate_stack.top() == pop_order[index_pop])
			{
				in_stack.erase(pop_order[index_pop]);
				simulate_stack.pop();
				++index_pop;
			}
			else
			{
				return false;
			}
		}
		else
		// push until match pop_order
		{
			in_stack.insert(push_order[index_push]);
			simulate_stack.push(push_order[index_push]);
			++index_push;
		}

	}
	return true;
}

bool isRightOrderText(vector<int> &push_order, vector<int> &pop_order)
{
	stack<int> simulate_stack;
	int index_push = 0, index_pop = 0;

	while (true)
	{
		if (index_pop == pop_order.size())
			if (simulate_stack.empty())
				return true;
			else
				return false;
		if (!simulate_stack.empty() && simulate_stack.top() == pop_order[index_pop])
		{
			simulate_stack.pop();
			++index_pop;
		}
		else
		{
			while (index_push < push_order.size() && (simulate_stack.empty() || simulate_stack.top() != pop_order[index_pop]))
			{
				simulate_stack.push(push_order[index_push]);
				++index_push;
			}
			if (index_push == push_order.size() && simulate_stack.top() != pop_order[index_pop])
				return false;
		}
	}
}

int main()
{
	vector<int> push_order({ 1, 2, 3, 4, 5 });
	vector<int> pop_order({ 4,5,3,2,1 });

	//cout << isRightOrder(push_order, pop_order) << endl;
	cout << isRightOrderText(push_order, pop_order) << endl;
	return 0;
}
 