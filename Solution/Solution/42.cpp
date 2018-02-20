#include <string>
#include <iostream>

using namespace std;

void ReverseWordCore(string &str, int ibegin, int iend)
{
	while (ibegin < iend)
	{
		swap(str[ibegin], str[iend]);
		++ibegin;
		--iend;
	}
}

void ReverseWord(string &str)
{
	ReverseWordCore(str, 0, str.size() - 1);

	int ibegin = 0, iend = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			ibegin = i;
			while (i < str.size() && str[i] != ' ')
				++i;
			iend = i;
			ReverseWordCore(str, ibegin, iend - 1);
		}
	}

}

void LeftReverseWordAtK(string &str, int k)
{
	if (k >= str.size())
		return;

	ReverseWordCore(str, 0, k - 1);

	ReverseWordCore(str, k, str.size() - 1);
	ReverseWordCore(str, 0, str.size() - 1);

}

void TestReverseWord()
{
string str;
	while (true)
	{
		getline(cin, str);
		ReverseWord(str);
		cout << str << endl;
	}
}

void TestLeftReverseWordAtK()
{
	string str, strtmp;
	getline(cin, str);
	strtmp = str;
	while (true)
	{
		int k;
		cin >> k;
		LeftReverseWordAtK(str, k);
		cout << str << endl;
		str = strtmp;
	}
}
//
//int main()
//{
//	TestLeftReverseWordAtK();
//
//	return 0;
//}