#include <iostream>
using namespace std;
int main()
{
    int x[5], count = 0;
    for (int i = 0; i < 5; ++i)
    {
        cin >> x[i];
        if ((x[i] > 1000000000) || (x[i] <= 0))
        {
            cout << "x > 10^9 || x <= 0" << endl;
            exit(0);
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (x[i] == x[j])
            {
                ++count;
            }
        }
    }
    switch (count)
    {
    case 25:
        cout << "poker" << endl;
        break;
    case 17:
        cout << "four of a kind" << endl;
        break;
    case 13:
        cout << "full house" << endl;
        break;
    case 11:
        cout << "three of a kind" << endl;
        break;
    case 9:
        cout << "two pairs" << endl;
        break;
    case 7:
        cout << "one pair" << endl;
        break;
    default:
        cout << "all different" << endl;
    }
}