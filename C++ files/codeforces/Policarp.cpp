#include <iostream>
using namespace std;
void SelectionSort(int *arr, const int size)
{
    int min = 0;
    int temp = 0;

    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main()
{
    int digits[4];
    for (int i = 0; i < 4; ++i)
        cin >> digits[i];
    SelectionSort(digits, 4);
    for (int i = 2; i >= 0; --i)
        cout << digits[3] - digits[i] << ' ';
}