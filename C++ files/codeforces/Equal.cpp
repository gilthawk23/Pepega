#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    set<int> values;
    int n, number;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> number;
        values.insert(values.end(), number);
    }
    vector<int> vect;
    for (int i : values)
    {
        vect.push_back(i);
    }
    if (values.size() > 3)
        cout << -1 << endl;
    else if (values.size() == 3)
    {
        int n1 = vect[2] - vect[1], n2 = vect[1] - vect[0];
        if (n1 == n2)
        {
            cout << n1 << endl;
        }
        else
            cout << -1 << endl;
    }
    else if (values.size() == 2)
    {
        int n1 = vect[0], n2 = vect[1];
        for (int i = 1; i <= 100; ++i)
        {
            n1 = vect[0], n2 = vect[1];
            n1 += i;
            n2 -= i;
            if (n1 == n2)
            {
                cout << i << endl;
                break;
            }
            n1 = vect[0], n2 = vect[1];
            n1 += i;
            if (n1 == n2)
            {
                cout << i << endl;
                break;
            }
            n1 = vect[0], n2 = vect[1];
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
    else if (values.size() == 1)
    {
        cout << 0 << endl;
    }
}