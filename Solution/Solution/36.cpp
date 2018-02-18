/*
 * 书上的方法多一个数组副本的输入参数，这样，在每一层调用中颠倒数组和副本的位置，就可以避免
 * 不必要的复制操作。
 */
#include <iostream>
#include <vector>

using namespace std;

int InversePairsCore(vector<int> &nums, int begin, int end)
{
	if (begin >= end)
		return 0;
	if (end - begin + 1 == 2)
	{
		if (nums[begin] > nums[end])
		{
			swap(nums[begin], nums[end]);
			return 1;
		}
		else
			return 0;
	}
		
	int res = 0;
	int mid = (begin + end) / 2;
	// Partition
	res += InversePairsCore(nums, begin, mid);
	res += InversePairsCore(nums, mid + 1, end);

	// Merge
	vector<int> nums_dum(end - begin + 1);
	int index1 = mid, index2 = end, index3 = end - begin;
	while (index1 >= begin && index2 >= mid + 1)
	{
		if (nums[index1] > nums[index2])
		{
			res += index2 - mid;
			nums_dum[index3--] = nums[index1--];
		}
		else
		{
			nums_dum[index3--] = nums[index2--];
		}
	}

	while (index1 >= begin)
	{
		nums_dum[index3--] = nums[index1--];
	}
	while (index2 >= mid + 1)
	{
		nums_dum[index3--] = nums[index2--];
	}

	for (int i = begin; i <= end; i++)
		nums[i] = nums_dum[i - begin];

	return res;
}

int InversePairs(vector<int> &nums)
{
	if (nums.size() <= 1)
		return 0;

	int res = 0;

	res = InversePairsCore(nums, 0, nums.size() - 1);

	return res;
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
//	cout << "Sum : " << InversePairs(nums) << endl;
//
//	return 0;
//}