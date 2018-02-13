#include <iostream>
#include <vector>

using namespace std;

// f(i) = max(f(i-1)+nums[i], nums[i])

int GetMaxSubSum(vector<int> &nums)
{
	int maxsum, cursum;
	maxsum = INT_MIN;
	cursum = 0;
	for (auto num : nums)
	{
		if (cursum <= 0)
			cursum = num;
		else
			cursum += num;

		if (cursum > maxsum)
			maxsum = cursum;
	}

	return maxsum;
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
//	cout << "Result:\t" << GetMaxSubSum(nums) << endl;
//
//	return 0;
//}