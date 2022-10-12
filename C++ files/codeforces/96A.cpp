#include <iostream>
using namespace std;
int main()
{
    int count;
    bool solve = 0;
    string position;
    cin >> position;
    for (int i = 0; i < position.length(); ++i)
    {
        if (position[i] == position[i + 1])
        {
            ++count;
            if (count >= 7)
            {
                cout << "YES\n";
                solve = 1;
                break;
            }
        }
        else
            count = 0;
    }
    if (!solve)
        cout << "NO\n";
}
