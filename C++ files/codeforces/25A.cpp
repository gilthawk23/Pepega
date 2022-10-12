#include <iostream>
using namespace std;
int main()
{
    int N, number[100];
    bool nc;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> number[i];
    }
    for (int i = 1; i < N; ++i)
    {
        if (number[i - 1] % 2 != number[i] % 2)
        {
            cout << i + 1 << endl;
            break;
        }
    }
}
