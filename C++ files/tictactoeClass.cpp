#include <iostream>
using namespace std;
class tictactoe
{
private:
    char field[3][3], firstmark, secondmark;

public:
    tictactoe()
    {
        for (size_t i = 0; i < 3; ++i)
        {
            for (size_t j = 0; j < 3; ++j)
            {
                field[i][j] = ' ';
            }
        }
        while (firstmark != 'X' && firstmark != 'O' && firstmark != 'o' && firstmark != 'x')
        {
            cout << "1st player is X or O?\n";
            cin >> firstmark;
        }
        switch (firstmark)
        {
        case 'x':
        {
            firstmark = 'X';
        }
        case 'X':
        {
            secondmark = 'O';
            break;
        }
        case 'o':
        {
            firstmark = 'O';
        }
        case 'O':
        {
            secondmark = 'X';
            break;
        }
        }
        cout << "\nTutorial:\nTo put a mark in a cell, you need to enter its row and column.\nThe player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner\n\n";
    }
    void showField()
    {
        cout << "1st player - " << firstmark << "   2nd player - " << secondmark << endl;
        for (size_t i = 0; i < 3; ++i)
        {
            cout << field[i][0] << "|" << field[i][1] << "|" << field[i][2];
            if (i != 2)
                cout << "\n-----";
            cout << endl;
        }
    }
    bool putMark(int x, int y, char mark)
    {
        if (field[x][y] != ' ')
        {
            cout << "Symbol already there! Try again!\n";
            return 1;
        }
        else
        {
            field[x][y] = mark;
            return 0;
        }
    }
    void firstplayermove()
    {
        int x, y;
        cout << "1st player move:";
        cin >> x >> y;
        while (putMark(x - 1, y - 1, firstmark))
            cin >> x >> y;
        cout << "\x1B[2J\x1B[H";
        showField();
    }
    void secondplayermove()
    {
        int x, y;
        cout << "2nd player move:";
        cin >> x >> y;
        while (putMark(x - 1, y - 1, secondmark))
            cin >> x >> y;
        cout << "\x1B[2J\x1B[H";
        showField();
    }
    bool checkforwinning()
    {
        for (size_t i = 0; i < 3; ++i)
        {
            if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != ' ')
            {
                if (firstmark == field[0][i])
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
                if (firstmark == field[0][i])
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
            if (firstmark == field[0][0])
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
            if (firstmark == field[0][2])
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
    char getFirstmark()
    {
        return firstmark;
    };
    ~tictactoe(){};
};
void playGame()
{
    tictactoe game;
    game.showField();
    if (game.getFirstmark() == 'X')
    {
        for (size_t i = 0; i < 2; ++i)
        {
            game.firstplayermove();
            game.secondplayermove();
        }
        for (size_t i = 0; i < 2; ++i)
        {
            game.firstplayermove();
            if (game.checkforwinning())
                return;
            game.secondplayermove();
            if (game.checkforwinning())
                return;
        }
        game.firstplayermove();
    }
    else
    {
        for (size_t i = 0; i < 2; ++i)
        {
            game.secondplayermove();
            game.firstplayermove();
        }
        for (size_t i = 0; i < 2; ++i)
        {
            game.secondplayermove();
            if (game.checkforwinning())
                return;
            game.firstplayermove();
            if (game.checkforwinning())
                return;
        }
        game.secondplayermove();
    }
    if (game.checkforwinning())
        return;
    cout << "Draw!\n";
    game.~tictactoe();
}
int main()
{
    char input;
    while (input != 'n' && input != 'N')
    {
        playGame();
        cout << "\nPlay one more time? (y/n)\n";
        cin >> input;
    }
}