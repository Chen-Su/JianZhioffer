/*
 * Cal1Times方法同书上的方法，只是没有将n转为字符串，这样导致每次都要递归计算位数，需要O(lgN)次，又递归调用lgN次，复杂度为O(lgNlgN)
 * 因此，应该还是先转化为字符串再处理比较好;
 */
#include <iostream>
#include <string>

using namespace std;

int NumberOf1(string &nstr)
{
	if (nstr.empty())
		return 0;
	if (nstr.size() == 1)
		if(nstr[0] == '0')
			return 0;
		else
			return 1;

	int res = 0;
	char first_digit = nstr[0];
	if (first_digit == '1')
	{
		res = stoi(nstr.substr(1)) + 1;
	}
	else if(first_digit > '1') // 不能只写else，例如100，第二次调用这里是00，会误增加次数
	{
		res = pow(10, nstr.size() - 1);
	}

	res += (first_digit - '0') * pow(10, nstr.size() - 2) * (nstr.size() - 1);

	return res + NumberOf1(nstr.substr(1));
}

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
		return 0;
	
	return NumberOf1(to_string(n));
}

int Cal1Times(int n)
{
	if (n <= 0)
		return 0;
	if (n < 10)
		return 1;

	// n 至少2位, 以n = 21345为例
	int res = 0;
	int digits = 0; // 位数
	int ntmp = n;
	while (ntmp)
	{
		ntmp = ntmp / 10;
		++digits;
	}
	cout << "digits : " << digits << endl;

	int first_digit = n / (pow(10, digits-1));
	cout << "first_digit : " << first_digit << endl;

	if (first_digit == 1)
	{
		res += n - pow(10, digits - 1) + 1;
	}
	else if(first_digit > 1)
	{
		// 1346 ~ 21345，最高位为1出现了1W次
		res += pow(10, digits - 1);
	}
	// 1346 ~ 21345，非最高位为1分段计算：
	// 1346 ~ 11345，非最高位为1出现了4 * 10^3 = 4000次
	// 11346 ~ 21345，同上
	// 因此总计为 4 * 10^3 * 2
	res += (digits - 1) * pow(10, digits - 2) * first_digit;

	// 第一次调用计算的是1346 ~ 21345中的次数，递归调用计算346 ~ 1345，以此类推
	return res + Cal1Times(n - first_digit * pow(10, digits-1));
}

//int main()
//{
//	int n;
//	while (true)
//	{
//		cin >> n;
//		cout << "Sum of 1 : " << Cal1Times(n) << endl;
//		cout << "Sum of 1 : " << NumberOf1Between1AndN(n) << endl;
//	}
//	return 0;
//}