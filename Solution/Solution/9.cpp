#include <iostream>

using namespace std;

long long getFibonacciRecursively(int n)
{
	if (n < 0)
		throw exception("input is invalid.");
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return getFibonacciRecursively(n - 1) + getFibonacciRecursively(n - 2);
}

long long getFibonacci(int n)
{
	if (n < 0)
		throw exception("input is invalid.");

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	long long pre = 1, prere = 0, res;
	for (int i = 2; i <= n; i++)
	{
		res = pre + prere;
		prere = pre;
		pre = res;
	}

	return res;
}

//int main()
//{
//	while (true)
//	{
//		try {
//			int n;
//			cin >> n;
//			cout << getFibonacci(n) << endl;
//			cout << getFibonacciRecursively(n) << endl;
//		}
//		catch (exception &e)
//		{
//			cout << e.what() << endl;
//		}
//	}
//
//	return 0;
//}