#include <iostream>
#include <string>

using namespace std;

void transString(string &str)
{
	if (str.empty())
		return;

	int space_num = 0;
	for (auto ch : str)
	{
		if (ch == ' ')
			space_num++;
	}
	int i = str.size() - 1;
	int j = str.size() + 2 * space_num - 1;
	for (int k = i; k < j; k++)
		str.append("0");

	for (; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else
		{
			str[j--] = str[i];
		}
	}
}

//int main()
//{
//	string str;
//
//	while(true)
//	{
//		getline(cin, str);
//		cout << str << endl;
//		cout << "Trans : ";
//		transString(str);
//		cout << str << endl;
//	}
//
//
//	return 0;
//}