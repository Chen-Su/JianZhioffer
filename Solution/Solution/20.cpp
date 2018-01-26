#include <iostream>

using namespace std;

void PrintCurCircle(int **matrix, int rows, int cols, int start_pos)
{
	// 用endx和endy来是代码更清晰易读
	int endx = cols - start_pos - 1;
	int endy = rows - start_pos - 1;

	// from left to right
	for (int i = start_pos; i <= endx; i++)
		cout << matrix[start_pos][i] << ' ';
	cout << endl;

	// from top to bottom
	if (endy > start_pos)
		for (int i = start_pos + 1; i <= endy; i++)
			cout << matrix[i][endx] << ' ';
	cout << endl;

	// from right to left
	if (endy > start_pos && endx > start_pos)
		for (int i = endx - 1; i >= start_pos; --i)
			cout << matrix[endy][i] << ' ';
	cout << endl;

	// from bottom to top
	if (endx > start_pos && endy > start_pos + 1)
		for (int i = endy - 1; i > start_pos; --i)
			cout << matrix[i][start_pos] << ' ';
	cout << endl;

	return;
}


void PrintMatrixClockwisely(int **matrix, int rows, int cols)
{
	// 忘记了检查指针为空
	if (matrix == NULL || rows <= 0 || cols <= 0)
		return;

	int start_pos = 0;
	while (start_pos <= (rows - 1) / 2)
	{
		PrintCurCircle(matrix, rows, cols, start_pos);
		start_pos++;
	}
}

void Test(int rows, int cols)
{
	int **matrix = new int*[rows];
	int cnt = 0;
	
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = ++cnt;
	}

	PrintMatrixClockwisely(matrix, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

//int main()
//{
//	Test(1, 1);
//	Test(1, 2);
//	Test(2, 2);
//	Test(2, 3);
//	Test(3, 2);
//	Test(3, 3);
//	Test(4, 4);
//
//
//
//
//	return 0;
//}