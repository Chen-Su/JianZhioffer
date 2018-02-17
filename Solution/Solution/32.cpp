/*
 * Cal1Times����ͬ���ϵķ�����ֻ��û�н�nתΪ�ַ�������������ÿ�ζ�Ҫ�ݹ����λ������ҪO(lgN)�Σ��ֵݹ����lgN�Σ����Ӷ�ΪO(lgNlgN)
 * ��ˣ�Ӧ�û�����ת��Ϊ�ַ����ٴ���ȽϺ�;
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
	else if(first_digit > '1') // ����ֻдelse������100���ڶ��ε���������00���������Ӵ���
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

	// n ����2λ, ��n = 21345Ϊ��
	int res = 0;
	int digits = 0; // λ��
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
		// 1346 ~ 21345�����λΪ1������1W��
		res += pow(10, digits - 1);
	}
	// 1346 ~ 21345�������λΪ1�ֶμ��㣺
	// 1346 ~ 11345�������λΪ1������4 * 10^3 = 4000��
	// 11346 ~ 21345��ͬ��
	// ����ܼ�Ϊ 4 * 10^3 * 2
	res += (digits - 1) * pow(10, digits - 2) * first_digit;

	// ��һ�ε��ü������1346 ~ 21345�еĴ������ݹ���ü���346 ~ 1345���Դ�����
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