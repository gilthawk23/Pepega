#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n <= 40 || n > 0)
    {
        if (n == 0 || n == 1)
            cout << 1 << endl;
        else
        {
            int value, n1 = 1, n2 = 1;
            for (int i = 1; i < n; ++i)
            {
                value = n1 + n2;
                n2 = n1;
                n1 = value;
            }
            cout << value << endl;
        }
    }
    else
        cout << "n > 40\t";
}