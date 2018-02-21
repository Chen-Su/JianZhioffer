#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int poker_nums = 5;


// 0 表示大小王，可代替任意牌
// 1 表示 A
// 11 表示 J
// 12 表示 Q
// 13 表示 K
bool IsContinuous(vector<int> &nums)
{
	if (nums.size() != poker_nums)
		throw exception("Invalid input.");

	int count_zero = 0;
	int count_gap = 0;

	sort(nums.begin(), nums.end());
	for (auto num : nums)
	{
		if (num == 0)
			count_zero++;
		else
			break;
	}
	int small = count_zero, big = count_zero + 1;
	while (big < nums.size())
	{
		if (nums[big] == nums[small])
			return false;
		count_gap += nums[big] - nums[small] - 1;
		++small;
		++big;
	}

	return count_gap <= count_zero;
}

//int main()
//{
//	vector<int> nums;
//	while (true)
//	{
//		for (int i = 0; i < poker_nums; i++)
//		{
//			int tmp;
//			cin >> tmp;
//			nums.push_back(tmp);
//		}
//		cout << "Res: ";
//		cout << IsContinuous(nums) << endl;
//		nums.clear();
//	}
//
//	return 0;
//}