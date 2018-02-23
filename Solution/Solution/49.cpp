/*
 * atoi()正溢出输出INT的最大正值，负溢出输出INT的最小负值
 * 而我写的版本没考虑溢出的情况。
 */
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isValid = true;

int StrToInt(string &str)
{
	if (str.empty())
	{
		isValid = false;
		return 0;
	}

	int res = 0;
	bool negative = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			// trans
			res = res * 10 + str[i] - '0';
		}
		else
		{
			if (i == 0 && str[i] == '+')
				continue;
			else if (i == 0 && str[i] == '-')
			{
				negative = true;
				continue;
			}
			else
			{
				isValid = false;
				return 0;
			}
		}
	}

	return negative ? -res : res;
}

//int main()
//{
//	while (true)
//	{
//		string str;
//		cin >> str;
//		cout << atoi(str.c_str()) << endl;
//		cout << StrToInt(str) << endl;
//	}
//	return 0;
//}