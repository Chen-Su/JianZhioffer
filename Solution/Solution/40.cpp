/*
 * 通过一次遍历得到一个异或结果，根据异或结果的一个非零比特位将数组划分为两部分
 * 每个部分刚好包含一个只出现一次的数。很有启发性的思路。
 * 写代码时注意，22行while循环，'&'的优先级低于'=='，不加括号会得到错误的结果。
 */

#include <iostream>
#include <vector>

using namespace std;

void FindNumsAppearOnce(vector<int> &nums, int &num1, int &num2)
{
	int midres = 0;

	for (auto num : nums)
		midres ^= num;


	int flag = 1;
	// Caution : & has lower priority than ==
	while ((midres & flag) == 0)
		flag = flag << 1;

	cout << flag << endl;

	num1 = num2 = 0;
	for (auto num : nums)
	{
		if (num & flag)
			num1 ^= num;
		else
			num2 ^= num;
	}


	return;
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
//	int num1, num2;
//	FindNumsAppearOnce(nums, num1, num2);
//
//	cout << "Num1 : " << num1 << "\t Num2 : " << num2 << endl;
//
//	return 0;
//}