#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
void cleanTerminal()
{
    cout << "\x1B[2J\x1B[H";
}

void runfan(int delay)
{
    cleanTerminal();
    cout << "    *    \n    *    \n    *    \n  *   *  \n*       *\n~whooosh~";
    Sleep(delay);
    cleanTerminal();
    cout << "*        \n  *      \n    * * *\n  *      \n*        \n~whooosh~";
    Sleep(delay);
    cleanTerminal();
    cout << "*       *\n  *   *  \n    *    \n    *    \n    *    \n~whooosh~";
    Sleep(delay);
    cleanTerminal();
    cout << "        *\n      *  \n* * *    \n      *  \n        *\n~whooosh~";
}

// cout << "1 0 0 0 0\n0 1 0 0 0\n0 0 1 1 1\n0 1 0 0 0\n1 0 0 0 0\n";
int main() // https://i.imgur.com/cgKRpvj.png
{
    cout << "Enter speed:";
    int delay;
    cin >> delay;
    while (true)
    {
        runfan(delay);
    }
}