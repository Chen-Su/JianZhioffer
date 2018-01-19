#include <iostream>
#include <vector>

using namespace std;

void ReorderOddEven(vector<int> &num_array)
{
	if (num_array.empty())
		return;
	int iodd = 0, ieven = num_array.size()-1;
	while (iodd < ieven)
	{
		if (!(num_array[iodd] & 0x1))
		{
			// even
			int tmp = num_array[iodd];
			num_array[iodd] = num_array[ieven];
			num_array[ieven] = tmp;
			--ieven;
		}
		else
			++iodd;
	}
}

//int main()
//{
//	int n;
//	cout << "Input nums : ";
//	cin >> n;
//	vector<int> num_array;
//	while (n--)
//	{
//		int tmp;
//		cin >> tmp;
//		num_array.push_back(tmp);
//	}
//
//	ReorderOddEven(num_array);
//
//	for (auto item : num_array)
//		cout << item << '\t';
//	cout << endl;
//
//	return 0; 
//}