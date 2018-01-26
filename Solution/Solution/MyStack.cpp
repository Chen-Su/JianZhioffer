#include "MyStack.h"
#include <iostream>

bool MyStack::push(int val)
{
	if (data.empty())
		minYet.push_back(val);
	else
		minYet.push_back(val < this->min() ? val : this->min());

	data.push_back(val);
	return true;
}

bool MyStack::pop()
{
	if (data.empty())
		return false;
	data.pop_back();
	minYet.pop_back();
	return true;
}

int MyStack::min()
{
	if (data.empty())
	{
		cerr << "Thers is no data in Stack.";
		return -1;
	}
	return minYet.back();
}

int MyStack::top()
{
	if (data.empty())
	{
		cerr << "Thers is no data in Stack.";
		return -1;
	}

	return data.back();
}
