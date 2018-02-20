/*
 *  第二问还是挺难想的，很有启发性
 */
#include <iostream>
#include <vector>

using namespace std;

void FindPair(vector<int> &nums, int sum)
{
	if (nums.empty())
		return;
	int ibegin = 0, iend = nums.size() - 1;
	while (ibegin < iend)
	{
		if (nums[ibegin] + nums[iend] < sum)
			++ibegin;
		else if (nums[ibegin] + nums[iend] == sum)
			break;
		else
			--iend;
	}
 
	if (ibegin >= iend)
		cout << "Not found a pair." << endl;
	else
		cout << "Pair : " << nums[ibegin] << "\t" << nums[iend] << endl;

	return;
}

void PrintSeq(int ibegin, int iend)
{
	for (auto i = ibegin; i <= iend; i++)
		cout << i << ' ';
	cout << endl;
}

void PrintSeqs(int sum)
{
	if (sum < 3)
		return;

	int ibegin = 1, iend = 2;
	int cur_sum = ibegin + iend;

	while (ibegin < (sum + 1) / 2)
	{
		if (cur_sum == sum)
		{
			PrintSeq(ibegin, iend);
			++iend;
			cur_sum += iend;
		}
		else if (cur_sum > sum)
		{
			cur_sum -= ibegin;
			++ibegin;
		}
		else
		{
			++iend;
			cur_sum += iend;
		}
	}

}

void TestFindPair()
{
	int n;
	cin >> n;
	vector<int> nums;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	int sum;
	while (true)
	{
		cin >> sum;
		FindPair(nums, sum);
	}
}

void TestPrintSeqs()
{
	while (true)
	{
		int n;
		cin >> n;
		PrintSeqs(n);
	}
}

//int main()
//{
//	
//	TestPrintSeqs();
//
//	return 0;
//}