#include <iostream>

using namespace std;



double PowerCore(double base, int exponent)
{
	if (exponent == 1)
		return base;
	if (exponent == 0)
		return 1;

	//double sub_power = PowerCore(base, exponent / 2);
	double sub_power = PowerCore(base, exponent >> 1);

	//if (exponent % 2 == 0)
	if ((exponent & 0x1) == 0)
		// 用位操作代替除2和奇偶判断
		return sub_power * sub_power;
	else
		return sub_power * sub_power * base;
}

double Power(double base, int exponent)
{
	if (base - 0 < 0.0000001 && exponent < 0)
		// 没有考虑到base为0指数为负数的情况，这种情况是非法的。
		// 用-1表示非法
		return -1;
	if (exponent < 0)
		return 1 / PowerCore(base, -1 * exponent);

	return PowerCore(base, exponent);
}

//int main()
//{
//
//	while (true)
//	{
//		int base, exp;
//		cin >> base >> exp;
//
//		cout << Power(base, exp) << endl;
//	}
//	return 0;
//}