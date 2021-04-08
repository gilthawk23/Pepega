#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
// Дано 20 чисел в диапазоне от 1 до 10. Отсортировать числа по частоте встречаемости
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int secondarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, minindex, arr[20], frequency[10] = {0};
	for (int i = 0; i < 20; ++i)
	{
		arr[i] = rand() % 10 + 1;
	}
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (arr[i] == secondarr[j])
			{
				++frequency[j];
			}
		}
	}
	cout << "array: ";
	for (int i = 0; i < 20; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl
		 << endl
		 << "numbers: \t";
	for (int i = 0; i < 10; ++i)
	{
		cout << secondarr[i] << " ";
	}
	cout << endl
		 << "frequency: \t";
	for (int i = 0; i < 10; ++i)
	{
		cout << frequency[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		minindex = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (frequency[j] > frequency[minindex])
			{
				minindex = j;
			}
		}
		swap(frequency[minindex], frequency[i]);
		swap(secondarr[minindex], secondarr[i]);
	}
	cout << endl
		 << "sorted number: \t";

	for (int i = 0; i < 10; ++i)
	{
		frequency[i] = frequency[i];
		cout << secondarr[i] << " ";
	}
	cout << endl
		 << "sorted freq.: \t";
	for (int i = 0; i < 10; ++i)
	{
		cout << frequency[i] << " ";
	}
	int j = 0;
	for (int i = 0; i < 20; ++i)
	{
		if (frequency[j] == 0)
		{
			j++;
		}
		if (frequency[j] != 0)
		{
			arr[i] = secondarr[j];
			frequency[j]--;
		}
	}

	cout << endl
		 << endl
		 << "sorted arr: ";
	for (int i = 0; i < 20; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}