#include <iostream>

using namespace std;

int AddSp(int a, int b)
{
	int res = 0;
	int carry = 0; // ½øÎ»

	do
	{
		res = a ^ b;
		carry = (a & b) << 1;

		a = res;
		b = carry;
	} while (carry);

	return res;
}

//
//int main()
//{
//	while (true)
//	{
//		int a, b;
//		cin >> a >> b;
//		cout << a + b << "\t" << AddSp(a, b) << endl;
//	}
//
//	return 0;
//}