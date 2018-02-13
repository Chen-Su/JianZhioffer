/*
 * FindTheNum() ����ʹ��һ��map����¼ÿ�������ֵĴ�����Ȼ���ٱ���һ��map���ҵ�ֵ��������һ���key
 * ע�⵽map[]������logN���Ӷȣ����ԣ��ڵ�һ����������ʱ���Ӷ�ΪO(NlogN)
 * Text1()�ǻ��ڿ�������patition()�ķ�����ƽ�����Ӷ�O(N)
 * Text2()���������Ŀ�����ԣ����Ӷ�O(N)��
 * ע������ַ�������Ҫ��������������ȷ�ԡ�
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int FindTheNum(vector<int> &nums)
{
	map<int, size_t> num_cnts;
	for (auto num : nums)
	{
		num_cnts[num]++;
	}

	for (auto &item : num_cnts)
	{
		if (item.second >= nums.size() / 2)
			return item.first;
	}
	throw exception("Not found.");
	return 0;
}

int partition(vector<int> &nums, int left, int right)
{
	int pivot = right;
	int small = left - 1;
	for (int index = left; index < right; ++index)
	{
		if (nums[index] < nums[pivot])
		{
			++small;
			swap(nums[small], nums[index]);
		}
	}
	swap(nums[small + 1], nums[pivot]);
	return small + 1;
}

int QuickFindMidlle(vector<int> &nums, int left, int right)
{
	// exit-condition
	if (nums.empty() || left > right)
		throw exception("InVaild Input");

	int pivot = partition(nums, left, right);
	int mid = nums.size() / 2 - 1;
	if (pivot == mid)
		return nums[pivot];
	else if (pivot > mid)
		return QuickFindMidlle(nums, left, pivot - 1);
	else
		return QuickFindMidlle(nums, pivot + 1, right);
}

int Text1(vector<int> &nums)
{
	return QuickFindMidlle(nums, 0, nums.size()-1);
}

int Text2(vector<int> &nums)
{
	if (nums.empty())
		throw exception("Invalid Input");

	int res = nums[0];
	int cnt = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		if (cnt > 0)
		{
			if (nums[i] == res)
				++cnt;
			else
				--cnt;
		}
		else
		{
			cnt = 1;
			res = nums[i];
		}
	}

	// need check validation

	return res;
}
//
//int main()
//{
//	vector<int> nums;
//	int n = 0;
//	cin >> n;
//	while (n--)
//	{
//		int tmp;
//		cin >> tmp;
//		nums.push_back(tmp);
//	}
//
//	try
//	{
//		cout << Text2(nums) << endl;
//		//cout << FindTheNum(nums) << endl;
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}