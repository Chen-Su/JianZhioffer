/*
 * 首先把数组中的数拼接起来，这是一个隐含的大数问题，应该想到用字符串处理。
 * 其次，这道题中，定义一种字符串比较方法来使用sort排序，很有启发性。
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp_33(string &sa, string &sb)
{
	string sab = sa + sb;
	string sba = sb + sa;

	return sab < sba;
}

void PrintMinNumber(vector<int> &nums)
{
	vector<string> snums;
	for (auto num : nums)
		snums.push_back(to_string(num));
	sort(begin(snums), end(snums), comp_33);

	for (auto snum : snums)
		cout << snum;
	cout << endl;
}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> nums;
//	while (n--)
//	{
//		int tmp;
//		cin >> tmp;
//		nums.push_back(tmp);
//	}
//
//	PrintMinNumber(nums);
//
//	return 0;
//}