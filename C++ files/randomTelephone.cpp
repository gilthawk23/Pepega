#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int digit;
    string number;
    bool solve = false;
    while (!solve)
    {
        cout << "\x1B[2J\x1B[H";
        digit = rand() % 10;
        cout << number << digit;
        if (getch() == 'y')
        {
            number += to_string(digit);
            if (number.length() == 11)
            {
                solve = true;
            }
        }
    }
}