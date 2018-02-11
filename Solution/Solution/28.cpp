#include <string>
#include <iostream>

using namespace std;

int cnt;

void PrintAllPermu(string &str, size_t index)
{
	if (str.empty())
		return;
	if (index == str.length() - 1)
	{
		cout << str << endl;
		++cnt;
	}
	for (size_t i = index; i < str.length(); i++)
	{
		swap(str[i], str[index]);
		PrintAllPermu(str, index + 1);
		swap(str[index], str[i]);
	}
}

//int main()
//{
//	string str;
//	cin >> str;
//	PrintAllPermu(str, 0);
//	cout << "Sum :" << cnt << endl;
//	return 0;
//}