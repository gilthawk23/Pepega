#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    bool solve = false;
    int tries = 0, invalue = 0, value = rand() % 10000;
    while (!solve)
    {
        cin >> invalue;
        if (invalue == value)
        {
            solve = true;
            cout << "Good job!\n";
        }
        else if (invalue > value)
        {
            cout << "Lesser\n";
            ++tries;
        }
        else
        {
            cout << "Bigger\n";
            ++tries;
        }
    }
    cout << "Solved in " << tries << " tries" << endl;
}