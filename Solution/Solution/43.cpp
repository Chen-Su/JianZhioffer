/*
 *  递归方法复杂度O(n!),迭代可以降低到O(n^2)
 */
#include <vector>
#include <iostream>

using namespace std;

const int max_throw_value = 6;

void ProbabilityRecursively(int remind_number, int sum, vector<int> &counts)
{
	if (remind_number == 0)
	{
		counts[sum]++;
	}
	else
	{
		for (int i = 1; i <= max_throw_value; i++)
			ProbabilityRecursively(remind_number - 1, sum + i, counts);
	}
}

void PrintProbabilityRecursively(int number)
{
	vector<int> counts(number*max_throw_value + 1, 0);

	ProbabilityRecursively(number, 0, counts);

	// Print
	double all_counts = pow(max_throw_value, number);
	for (int i = number; i <= number*max_throw_value; i++)
	{
		cout << "sum : " << i << "\t prob : " << static_cast<double>(counts[i]) / all_counts << endl;
	}
}

void PrintProbabilityIteratively(int number)
{
	vector<int> counts(number*max_throw_value + 1);
	vector<int> counts_next(counts);

	// initial
	for (int i = 1; i <= max_throw_value; i++)
		counts[i] = 1;

	// iterate
	for (int i = 2; i <= number; i++)
	{
		for (int j = i; j <= i * max_throw_value; j++)
		{
			// 以i=2为例
				if (j == i)
				{
					// 2
					counts_next[j] = 1;
				}
				else if (j < i + max_throw_value)
				{
					// 3 ~ 7
					counts_next[j] = counts_next[j - 1] + counts[j - 1];
				}
				else
				{	// 8 ~ 12
					counts_next[j] = counts_next[j - 1] - counts[j - 1 - max_throw_value] + counts[j - 1];
				}
		}
		counts.swap(counts_next);
	}

	// Print
	double all_counts = pow(max_throw_value, number);
	for (int i = number; i <= number*max_throw_value; i++)
	{
		cout << "sum : " << i << "\t prob : " << static_cast<double>(counts[i]) / all_counts << endl;
	}

}
//
//int main()
//{
//	int n;
//	while (true)
//	{
//		cin >> n;
//		PrintProbabilityRecursively(n);
//		cout << "-------------------------" << endl;
//		PrintProbabilityIteratively(n);
//	}
//
//
//	return 0;
//}