#include "MyStack.h"
#include <iostream>

int main()
{
	MyStack s;

	for (int i = 0; i < 10; i++)
		s.push(i);

	cout << s.min() << endl;

	s.pop();
	cout << s.min() << endl;
	s.push(-1);
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.push(-1);
	cout << s.min() << endl;
	while (s.pop())
		;
	cout << s.min() << endl;
	return 0;
}