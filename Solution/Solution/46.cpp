/*
 * 分别使用了构造函数与静态成员变量(S1),递归调用虚函数(S2), 函数指针(S3), 模板编程
 * S1利用了静态成员变量的性质， S2，S3利用同一个指针可以指向不同的对象或函数(多态)的性质
 * S4利用了非类型参数的模板函数(Non-type parameters for Function templates)，和模板特例化(Template specialization)（http://www.cplusplus.com/doc/oldtutorial/templates/）
 */
#include <iostream>

using namespace std;

// S1
class Solution1 
{
	static int N;
	static int Sum;
public:
	Solution1()
	{
		++N;
		Sum += N;
	}
	static int GetSum(int n)
	{
		Solution1 *s1 = new Solution1[n];
		delete[] s1;
		return Solution1::Sum;
	}
};

int Solution1::N = 0;
int Solution1::Sum = 0;

// S2
class Solution2End;
Solution2End *s2[2];

class Solution2End
{
public:
	virtual int GetSum(int n)
	{
		return 0;
	}
};

class Solution2 : public Solution2End
{
public:
	
	virtual int GetSum(int n)
	{
		return s2[!!(n-1)]->GetSum(n - 1) + n;
	}
};

int Solution2GetSum(int n)
{
	s2[0] = new Solution2End;
	s2[1] = new Solution2;

	int res = s2[!!n]->GetSum(n);

	delete s2[0];
	delete s2[1];

	return res;
}

// S3
using FuncPtr = int(*)(int);
FuncPtr s3[2];

int Solution3End(int n)
{
	return 0;
}

int Solution3(int n)
{
	return s3[!!(n - 1)](n - 1) + n;
}

int Solution3GetSum(int n)
{
	s3[0] = Solution3End;
	s3[1] = Solution3;
	
	int res = s3[!!n](n);

	return res;
}

// S4
// non-type parameter for template
template<int N>
int GetSum()
{
	return GetSum<N - 1>() + N;
}

// template specialization
template <>
int GetSum<1>()
{
	return 1;
}


//int main()
//{
//	int n;
//	cin >> n;
//
//	// S1
//	cout << Solution1::GetSum(n) << endl;
//	
//	// S2
//	cout << Solution2GetSum(n) << endl;
//
//	// S3
//	cout << Solution3GetSum(n) << endl;
//
//	// S4
//	cout << GetSum<100>() << endl;
//
//	return 0;
//}