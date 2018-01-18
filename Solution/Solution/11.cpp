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
		// ��λ���������2����ż�ж�
		return sub_power * sub_power;
	else
		return sub_power * sub_power * base;
}

double Power(double base, int exponent)
{
	if (base - 0 < 0.0000001 && exponent < 0)
		// û�п��ǵ�baseΪ0ָ��Ϊ�������������������ǷǷ��ġ�
		// ��-1��ʾ�Ƿ�
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