/*
 * �����캯����Ϊprivate������ֹ�̳�
 * S1������Ԫ��������Ԫ��������private���캯��
 * S2��������̳�
 */
#include <iostream>

using namespace std;

// S1
class SealedClass1;

SealedClass1 ConstructSealedClass1();

class SealedClass1
{
public:
	//static SealedClass1* ConstructSealedClass1()
	//{
	//	return new SealedClass1;
	//}
	//static void DestructSealedClass1(SealedClass1* s1)
	//{
	//	delete s1;
	//}
	friend SealedClass1 ConstructSealedClass1();
private:
	SealedClass1()
	{
		cout << "Construct." << endl;
	}
	~SealedClass1() {}
};

SealedClass1 ConstructSealedClass1()
{
	return SealedClass1();
}

// S2
template<typename T>
class MakeSealed
{
	friend T;
private:
	MakeSealed(){}
	~MakeSealed() {}
};

class SealedClass2 : virtual public MakeSealed<SealedClass2>
{
public:
	SealedClass2() { cout << "Construct." << endl; }
	~SealedClass2(){}
};
//
//int main()
//{
//	// S1
//	//auto s1 = SealedClass1::ConstructSealedClass1();
//	//SealedClass1::DestructSealedClass1(s1);
//
//	// auto s1 = ConstructSealedClass1();
//
//	// S2
//	SealedClass2 s2;
//
//	return 0;
//}
