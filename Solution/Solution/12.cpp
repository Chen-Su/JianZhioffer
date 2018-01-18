/*
 * 这道题注意不能用int或long long来表示数字，这些类型很容易溢出，在这个问题中不适合。
 * 因此要考虑使用字符串来表示数字，属于大数问题。
 */
#include <iostream>
#include <string>

using namespace std;

char numbers[] = "0123456789";

void PrintNumber(string snumber)
{
	bool startPrint = false;
	for (auto ch : snumber)
	{
		if (ch != '0')
			startPrint = true;
		if (startPrint)
			printf("%c", ch);
	}
}

void Print1toNNumberCore(string prefix, int n)
{
	if (n <= 0)
		return;

	if (n == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			PrintNumber(prefix + numbers[i]);
			printf("\t");
		}
	}
	else 
	{
		for (int i = 0; i < 10; i++)
		{
			Print1toNNumberCore(prefix + numbers[i], n - 1);
		}
	}
}


void Print1toNNumberRecursively(int n)
{
	Print1toNNumberCore("", n);
}


// 每次对op表示的数字进行加一操作
bool Increment(string &op)
{
	bool isIncrement = true;	// 表示是否进位

	for (int i = op.size() - 1; i >= 0; i--)
	{
		int tmp = op[i] - '0';
		if (isIncrement)
			++tmp;
		if (tmp >= 10)
		{
			isIncrement = true;
			tmp = tmp % 10;
		}
		else
		{
			isIncrement = false;			
		}
		op[i] = '0' + tmp;

	}

	return isIncrement;
}


void Print1toNNumber(int n)
{
	if (n <= 0)
		return;
	string op(n, '0');
	
	while (!Increment(op))
	{
		PrintNumber(op);
		cout << "\t";
	}
}

//
//int main()
//{
//	while (true)
//	{
//		int n;
//		cin >> n;
//		//Print1toNNumberRecursively(n);	// 递归方法
//		Print1toNNumber(n);					// 模拟方法
//		cout << endl;
//	}
//	return 0;
//}