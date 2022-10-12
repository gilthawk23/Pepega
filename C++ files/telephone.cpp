#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;
int main()
{
    bool solve = false;
    int counter = 0;
    srand(time(0));
    while (!solve)
    {
        cout << "\x1B[2J\x1B[H";
        cout << "Is this your telephone number? (y/n): +8 ";
        for (int i = 0; i < 10; ++i)
        {
            cout << rand() % 10;
            if ((i == 2) || (i == 5) || (i == 7))
                cout << " ";
        }
        if (getch() == 'y')
            solve = true;
        else
            ++counter;
    }
    cout << endl
         << "Solved in " << counter << " tries";
}
