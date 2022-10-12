#include <iostream>
#include <ctime>
using namespace std;
void initField(char (*field)[3])
{
    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 3; ++j)
        {
            field[i][j] = ' ';
        }
        cout << field[i][0] << "|" << field[i][1] << "|" << field[i][2];
        if (i != 2)
            cout << "\n-----";
        cout << endl;
    }
}
void showField(char (&field)[3][3])
{
    for (size_t i = 0; i < 3; ++i)
    {
        cout << field[i][0] << "|" << field[i][1] << "|" << field[i][2];
        if (i != 2)
            cout << "\n-----";
        cout << endl;
    }
}
bool putSymbol(int x, int y, char (&field)[3][3], char symbol)
{
    if (field[x][y] != ' ')
    {
        cout << "Symbol already there! Try again!\n";
        return 1;
    }
    else
    {
        field[x][y] = symbol;
        return 0;
    }
}
void firstplayermove(char (&field)[3][3], char symbol)
{
    int x, y;
    cout << "1st player move:";
    cin >> x >> y;
    while (putSymbol(x - 1, y - 1, field, symbol))
        cin >> x >> y;
    showField(field);
}
void secondplayermove(char (&field)[3][3], char symbol)
{
    int x, y;
    cout << "2nd player move:";
    cin >> x >> y;
    while (putSymbol(x - 1, y - 1, field, symbol))
        cin >> x >> y;
    showField(field);
}
bool checkforwinning(char (&field)[3][3], char firstsymbol, char secondsymbol)
{
    for (size_t i = 0; i < 3; ++i)
    {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != ' ')
        {
            if (firstsymbol == field[0][i])
            {
                cout << "1st player win!\n";
                return 1;
            }
            else
            {
                cout << "2nd player win!\n";
                return 1;
            }
        }
        else if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != ' ')
        {
            if (firstsymbol == field[0][i])
            {
                cout << "1st player win!\n";
                return 1;
            }
            else
            {
                cout << "2nd player win!\n";
                return 1;
            }
        }
    }
    if (field[0][0] == field[1][1] && field[1][1] == field[2][2])
    {
        if (firstsymbol == field[0][0])
        {
            cout << "1st player win!\n";
            return 1;
        }
        else
        {
            cout << "2nd player win!\n";
            return 1;
        }
    }
    else if (field[0][2] == field[1][1] && field[1][1] == field[2][0])
    {
        if (firstsymbol == field[0][2])
        {
            cout << "1st player win!\n";
            return 1;
        }
        else
        {
            cout << "2nd player win!\n";
            return 1;
        }
    }
    return 0;
}
int main()
{
    char tttField[3][3], firstsymbol, secondsymbol;
    while (firstsymbol != 'X' && firstsymbol != 'O')
    {
        cout << "Enter 1st player's symbol, X or O\n";
        cin >> firstsymbol;
    }
    firstsymbol == 'X' ? secondsymbol = 'O' : secondsymbol = 'X';
    initField(tttField);
    for (size_t i = 0; i < 2; ++i)
    {
        firstplayermove(tttField, firstsymbol);
        secondplayermove(tttField, secondsymbol);
    }
    for (size_t i = 0; i < 2; ++i)
    {
        firstplayermove(tttField, firstsymbol);
        if (checkforwinning(tttField, firstsymbol, secondsymbol))
            exit(0);
        secondplayermove(tttField, secondsymbol);
        if (checkforwinning(tttField, firstsymbol, secondsymbol))
            exit(0);
    }
    firstplayermove(tttField, firstsymbol);
    if (checkforwinning(tttField, firstsymbol, secondsymbol))
        exit(0);
    cout << "Draw!\n";
}