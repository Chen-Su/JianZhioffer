#include <iostream>
#include <list>

using namespace std;

int FindLastElem(int n, int m)
{
	if (m <= 0 || n <= 0)
		throw exception("Invalid input.");

	list<int> li;
	for (int i = 0; i < n; i++)
		li.push_back(i);

	list<int>::iterator it_cur = li.begin();
	while (li.size() > 1)
	{
		// Erase mth element
		for (int i = 0; i < m - 1; i++)
		{
			++it_cur;
			if (it_cur == li.end())
				it_cur = li.begin();
		}
		auto it_next = ++it_cur;
		if (it_next == li.end())
			it_next = li.begin();

		--it_cur;
		li.erase(it_cur);
		it_cur = it_next;
	}

	return li.front();
}
//
//int main()
//{
//	while (true)
//	{
//		int m, n;
//		cin >> n >> m;
//
//		cout << "Res : " << FindLastElem(n, m) << endl;
//	}
//
//	return 0;
//}