/*
 * �����ע�ⲻ����int��long long����ʾ���֣���Щ���ͺ��������������������в��ʺϡ�
 * ���Ҫ����ʹ���ַ�������ʾ���֣����ڴ������⡣
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


// ÿ�ζ�op��ʾ�����ֽ��м�һ����
bool Increment(string &op)
{
	bool isIncrement = true;	// ��ʾ�Ƿ��λ

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
//		//Print1toNNumberRecursively(n);	// �ݹ鷽��
//		Print1toNNumber(n);					// ģ�ⷽ��
//		cout << endl;
//	}
//	return 0;
//}