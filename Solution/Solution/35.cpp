#include <iostream>
#include <string>

using namespace std;

char FirstOnceChar(string &str)
{
	char res = 0;
	int alph_size = 256;
	int *alph_hash = new int[alph_size];
	for (int i = 0; i < alph_size; ++i)
		alph_hash[i] = 0;

	for (auto ch : str)
	{
		++alph_hash[tolower(ch)];
	}

	for (auto ch : str)
	{
		if (alph_hash[tolower(ch)] == 1)
		{
			res = ch;
			break;
		}
	}
	
	delete[] alph_hash;

	return res;
}

int main()
{
	string str;
	cin >> str;

	cout << FirstOnceChar(str) << endl;

	return 0;
}