#include <iostream>

using namespace std;

int getOneNums(int n)
{
	int cnt = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			cnt++;
		flag = flag << 1;
	}
	
	return cnt;
}

int getOneNumsAdvanced(int n)
{
	// 因为n-1会使n最右边的1变为0，因此n = n & (n-1)可以消除n中最右边的1
	int cnt = 0;
	while (n)
	{
		++cnt;
		n = n & (n - 1);
	}

	return cnt;
}

//int main()
//{
//	while (true)
//	{
//		int n;
//		cin >> n;
//		cout << "There're " << getOneNums(n) << " \'1\' in " << n << endl;
//		cout << "There're " << getOneNumsAdvanced(n) << " \'1\' in " << n << endl;
//		
//	}
//
//	return 0;
//}