#include <iostream>
#include <vector>

using namespace std;

int GetFirstK(vector<int> &nums, int begin, int end, int k)
{
	if (begin > end)
		throw exception("Not found.");

	int mid = (end + begin) / 2;

	if (nums[mid] == k && (mid == 0 || nums[mid - 1] < k))
	{
		return mid;
	}
	if (nums[mid] < k)
	{
		return GetFirstK(nums, mid + 1, end, k);
	}

	return GetFirstK(nums, begin, mid - 1, k);
}

int GetLastK(vector<int> &nums, int begin, int end, int k)
{
	if (begin > end)
		throw exception("Not Found.");

	int mid = (end + begin) / 2;

	if (nums[mid] == k && (mid == nums.size() - 1 || nums[mid + 1] > k))
		return mid;

	if (nums[mid] > k)
		return GetLastK(nums, begin, mid - 1, k);

	return GetLastK(nums, mid + 1, end, k);
}

int GetNumberOfK(vector<int> &nums, int k)
{
	if (nums.empty())
		return 0;

	int ileft = GetFirstK(nums, 0, nums.size() - 1, k);
	int iright = GetLastK(nums, 0, nums.size() - 1, k);

	return iright - ileft + 1;
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
//	while (true)
//	{
//		cout << "Input k : ";
//		cin >> n;
//		cout << endl;
//		cout << "count : " << GetNumberOfK(nums, n) << endl;
//	}
//
//	return 0;
//}
