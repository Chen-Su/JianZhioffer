#include <iostream>
#include <stack>

using namespace std;

template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T &node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};


//
//int main()
//{
//	CQueue<int> cq;
//
//	try {
//		cout << cq.deleteHead();
//	}
//	catch (std::exception &e)
//	{
//		cout << e.what() << endl;
//	}
//
//	cq.appendTail(1);
//	cq.appendTail(2);
//	cq.appendTail(3);
//
//	try {
//		cout << cq.deleteHead();
//		cout << cq.deleteHead();
//		cout << cq.deleteHead();
//		cout << cq.deleteHead();
//	}
//	catch (std::exception &e)
//	{
//		cout << e.what() << endl;
//	}
//	
//	return 0;
//}

template<typename T>
CQueue<T>::CQueue(void) : stack1(stack<T>()), stack2(stack<T>())
{
	
}

template<typename T>
CQueue<T>::~CQueue(void)
{

}

template<typename T>
void CQueue<T>::appendTail(const T & node)
{
	stack1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead()
{
	//if (stack1.empty() && stack2.empty())
	//{
	//	throw new exception("CQueue is empty.");
	//}
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			T &node = stack1.top();
			stack1.pop();
			stack2.push(node);
		}
	}

	if (stack2.empty())
	{
		throw exception("queue is empty");
	}

	T node = stack2.top();
	stack2.pop();
	return node;
}
