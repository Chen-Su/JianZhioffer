#include <vector>
#include <iostream>
#include <set>
#include <functional> // std::greater

using namespace std;

int patition(vector<int> &nums, int left, int right)
{
	// validation

	int small = left - 1;
	for (int index = left; index < right; ++index)
	{
		if (nums[index] < nums[right])
		{
			++small;
			swap(nums[small], nums[index]);
		}
	}
	swap(nums[small + 1], nums[right]);

	return small + 1;
}

vector<int> FindKSmallest(vector<int> &nums, int k)
{
	if (k <= 0 || k > nums.size())
		throw exception("Invalid Input.");

	int left = 0, right = nums.size() - 1;
	while (true)
	{
		int pivot = patition(nums, left, right);
		if (pivot == k)
			break;
		else if (pivot < k)
			left = pivot + 1;
		else
			right = pivot - 1;
	}

	return vector<int>(begin(nums), begin(nums) + k);
}

vector<int> Text2(vector<int> &nums, int k)
{
	multiset<int, greater<int>> num_set;
	for (auto num : nums)
	{
		if (num_set.size() < k)
		{
			num_set.insert(num);
		}
		else
		{
			if (num < *(begin(num_set)))
			{
				num_set.erase(begin(num_set));
				num_set.insert(num);
			}
		}
	}

	return vector<int>(begin(num_set), end(num_set));
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
//	int k;
//	cin >> k;
//	auto res = Text2(nums, k);
//
//	cout << "Result:\t";
//	for (auto num : res)
//		cout << num << ' ';
//	cout << endl;
//
//	return 0;
//}