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
void DeleteElement(int *arr, int &size, const int index)
{
    for (int i = index; i < size; ++i)
    {
        arr[i] = arr[i + 1];
    }
    --size;
}
int main()
{
    int values[100], n;
    cin >> n;
    if (n > 100 || n < 1)
    {
        cout << "1 <= n <= 100\t";
        exit(0);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
        if (values[i] > 100 || values[i] < 1)
        {
            cout << "1 <= value <= 100\t";
            exit(0);
        }
    }
    SelectionSort(values, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (values[i] == values[j] && j != i)
            {
                DeleteElement(values, n, i);
            }
        }
    }
    if (n > 3)
        cout << -1 << endl;
    else if (n == 3)
    {
        int n1 = values[2] - values[1], n2 = values[1] - values[0];
        if (n1 == n2)
            cout << n1 << endl;
        else
            cout << -1 << endl;
    }
    else if (n == 2)
    {
        int n1 = values[0], n2 = values[1];
        for (int i = 1; i <= 100; ++i)
        {
            n1 = values[0], n2 = values[1];
            n1 += i;
            n2 -= i;
            if (n1 == n2)
            {
                cout << i << endl;
                break;
            }
            n1 = values[0], n2 = values[1];
            n1 += i;
            if (n1 == n2)
            {
                cout << i << endl;
                break;
            }
            n1 = values[0], n2 = values[1];
            n2 -= i;
            if (n1 == n2)
            {
                cout << i << endl;
                break;
            }
            if (i == 100)
            {
                cout << -1 << endl;
            }
        }
    }
    else if (n == 1)
    {
        cout << 0 << endl;
    }
}