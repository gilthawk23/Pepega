#include <iostream>
using namespace std;
int main()
{
    int p, m, n;
    cin >> m >> n;
    p = m * n;
    if (p % 2 == 1)
        --p;
    cout << p / 2;
}