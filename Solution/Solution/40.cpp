/*
 * ͨ��һ�α����õ�һ��������������������һ���������λ�����黮��Ϊ������
 * ÿ�����ָպð���һ��ֻ����һ�ε��������������Ե�˼·��
 * д����ʱע�⣬22��whileѭ����'&'�����ȼ�����'=='���������Ż�õ�����Ľ����
 */

#include <iostream>
#include <vector>

using namespace std;

void FindNumsAppearOnce(vector<int> &nums, int &num1, int &num2)
{
	int midres = 0;

	for (auto num : nums)
		midres ^= num;


	int flag = 1;
	// Caution : & has lower priority than ==
	while ((midres & flag) == 0)
		flag = flag << 1;

	cout << flag << endl;

	num1 = num2 = 0;
	for (auto num : nums)
	{
		if (num & flag)
			num1 ^= num;
		else
			num2 ^= num;
	}


	return;
}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> nums;
//	while (n--)
//	{
//		int tmp;
//		cin >> tmp;
//		nums.push_back(tmp);
//	}
//
//	int num1, num2;
//	FindNumsAppearOnce(nums, num1, num2);
//
//	cout << "Num1 : " << num1 << "\t Num2 : " << num2 << endl;
//
//	return 0;
//}