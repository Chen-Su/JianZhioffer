/*
 * ���Ȱ������е���ƴ������������һ�������Ĵ������⣬Ӧ���뵽���ַ�������
 * ��Σ�������У�����һ���ַ����ȽϷ�����ʹ��sort���򣬺��������ԡ�
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