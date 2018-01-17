#include <iostream>
#include <vector>

using namespace std;

int finMinInOrder(vector<int> input_array, int left, int right)
{
	int res = input_array[left];
	for (int i = left; i <= right; i++)
	{
		res = res < input_array[i] ? res : input_array[i];
	}

	return res;
}

int findMin(vector<int> input_array)
// 要求序列中不含相同元素
{
	// this is shit
	if (input_array.empty())
		throw exception("Input empty.");
	if (input_array.size() == 1)
		return input_array[0];

	int left = 0, right = input_array.size() - 1;
	int mid = left;
	while (input_array[left] >= input_array[right])
	{
		if (left + 1 == right)
		{
			mid = right;
			break;
		}
		mid = (right + left) / 2;
		
		if (input_array[mid] == input_array[right] &&
			input_array[mid] == input_array[left])
			return finMinInOrder(input_array, left, right);

		if (input_array[mid] >= input_array[left])
		{
			left = mid;
		} 
		else
		{
			right = mid;
		}
	}
	
	return input_array[mid];
}

//int main()
//{
//	cout << "Input list num : ";
//	int n;
//	cin >> n;
//	cout << "Input a rotated accend list : ";
//	vector<int> input_array;
//	while (n--) {
//		int tmp;
//		cin >> tmp;
//		input_array.push_back(tmp);
//	}
//
//	try {
//		cout << "Mininum element is : " << findMin(input_array) << endl;
//	}
//	catch (exception &e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}