/*
 * NthUglyNumber()与书上的方法的不同之处在于去重的方法
 * 事实上，当丑数出现重复的时候，只可能与已经找到的丑数中的最大丑数重复。
 * 可以用反证法证明。
 */
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int NthUglyNumber(int n)
{
	if (n <= 0)
		return 0;
	vector<int> ugly_nums;
	ugly_nums.push_back(1);
	int cnt = 1;
	int it2, it3, it5;
	it2 = it3 = it5 = 0;

	while (cnt < n)
	{
		int smallest = ugly_nums[it2] * 2;
		int *itsmallest = &it2;
		if (ugly_nums[it3] * 3 < smallest)
		{
			smallest = ugly_nums[it3] * 3;
			itsmallest = &it3;
		}
		if (ugly_nums[it5] * 5 < smallest)
		{
			smallest = ugly_nums[it5] * 5;
			itsmallest = &it5;
		}
		++(*itsmallest);
		if (smallest == ugly_nums.back())
			// skip dumplicate
			continue;
		ugly_nums.push_back(smallest);
		
		++cnt;
	}

	return ugly_nums[cnt - 1];
}

int Min(int a, int b, int c)
{
	int min = a > b ? b : a;
	min = min > c ? c : min;
	return min;
}

int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;
	
	vector<int> ugly_nums;
	ugly_nums.push_back(1);
	int cnt = 1;
	int it2, it3, it5;
	it2 = it3 = it5 = 0;
	while (cnt < index)
	{
		
		int smallest = Min(ugly_nums[it2] * 2, ugly_nums[it3] * 3, ugly_nums[it5] * 5);
		ugly_nums.push_back(smallest);
		
		while (ugly_nums[it2] * 2 <= smallest)
			++it2;
		while (ugly_nums[it3] * 3 <= smallest)
			++it3;
		while (ugly_nums[it5] * 5 <= smallest)
			++it5;
		++cnt;
	}

	return ugly_nums.back();
}
//
//int main()
//{
//	while(true)
//	{
//		int n;
//		cin >> n;
//		cout << NthUglyNumber(n) << endl;
//		cout << GetUglyNumber(n) << endl;
//		
//	}
//
//	return 0;
//}