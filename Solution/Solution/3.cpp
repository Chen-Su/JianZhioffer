#include <iostream>

using namespace std;

bool isExist(int *data, int rows, int cols, int testnum)
{
	// get rows, cols
	// search from top-right
	int i = 0, j = cols-1;
	while (true) {
		if (i >= rows || j < 0)
			return false;
		if (data[i*cols + j] == testnum)
			return true;
		else if (data[i*cols + j] < testnum)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
}

bool isExist_text(int *matrix, int rows, int cols, int number)
{
	bool found = false;

	if (matrix != NULL && rows > 0 && cols > 0) // 检查输入的合法性
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && cols > 0)
		{
			if (matrix[row*cols + col] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row*cols + col] > number)
			{
				--col;
			}
			else
			{
				++row;
			}
		}
	}

	return found;
}

int main()
{
	int data[] = {
		1, 2, 8, 9 ,
		2, 4, 9, 12 ,
		4, 7, 10, 13 ,
		6, 8, 11, 15 ,
	};
	int rows, cols;
	rows = cols = 4;

	while (true)
	{
		int testnum;
		cin >> testnum;
		auto res = isExist(data, cols, rows, testnum);
		cout << res << endl;
	}
}