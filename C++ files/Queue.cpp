// Task from yandex.practicum
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<bool> worried;
	int q, WORRY_COUNT = 0, value;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		string operation_code;
		cin >> operation_code;
		if (operation_code == "WORRY_COUNT"s)
		{
			cout << WORRY_COUNT << endl;
		}
		else if (operation_code == "COME"s)
		{
			cin >> value;
			if (value < 0)
			{
				for (int i = worried.size() + value; i < worried.size(); ++i)
				{
					if (worried[i] == 1)
					{
						WORRY_COUNT--;
					}
				}
			}
			worried.resize(worried.size()+value);
		}
		else if (operation_code == "QUIET"s)
		{
			cin >> value;
			if (worried[value] == 1) {
				worried[value] = 0;
				WORRY_COUNT--;
			}
		}
		else if (operation_code == "WORRY"s)
		{
			cin >> value;
			if (worried[value] == 0) {
				worried[value] = 1;
				WORRY_COUNT++;
			}
		}
	}
}