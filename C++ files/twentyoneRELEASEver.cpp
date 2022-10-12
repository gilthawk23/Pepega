#include <iostream>
#include <ctime>
#include <cmath>
#define DEBUG
using namespace std;
class twentyone
{
    int cards[9] = {4, 4, 4, 4, 4, 4, 4, 4, 4}, firstPlayerScore = 0, secondPlayerScore = 0;

public:
    int firstPlayerGetsCard()
    {
        int index = rand() % 9;
        while (isIndexEmpty(index))
        {
            index = rand() % 9;
        }
        --cards[index];
        firstPlayerScore += indexToPoints(index);
        return indexToPoints(index);
    }
    int secondPlayerGetsCard()
    {
        int index = rand() % 9;
        while (isIndexEmpty(index))
        {
            index = rand() % 9;
        }
        --cards[index];
        secondPlayerScore += indexToPoints(index);
        return indexToPoints(index);
    }
    int getFirstScore()
    {
        return firstPlayerScore;
    }
    int getSecondScore()
    {
        return secondPlayerScore;
    }
    int indexToPoints(int index)
    {
        switch (index)
        {
        case 5:
        {
            return 2;
        }
        case 6:
        {
            return 3;
        }
        case 7:
        {
            return 4;
        }
        case 8:
        {
            return 11;
        }
        }
        return index + 6;
    }
    bool isIndexEmpty(int index)
    {
        bool value;
        cards[index] > 0 ? value = false : value = true;
        return value;
    }
    int determineWinner()
    {
        if (firstPlayerScore == secondPlayerScore)
        {
            cout << "\t\t---Draw!---\n\n";
            return 0;
        }
        else
        {
            if (firstPlayerScore > 21 && secondPlayerScore <= 21)
            {
                cout << "\t---2nd player wins!---\n\n";
                return 2;
            }
            else if (secondPlayerScore > 21 && firstPlayerScore <= 21)
            {
                cout << "\t---1st player wins!---\n\n";
                return 1;
            }
            else if (abs(21 - firstPlayerScore) < abs(21 - secondPlayerScore))
            {
                cout << "\t---1st player wins!---\n\n";
                return 1;
            }
            else if (abs(21 - firstPlayerScore) > abs(21 - secondPlayerScore))
            {
                cout << "\t---2nd player wins!---\n\n";
                return 2;
            }
            else
                cout << "\n\n\tSomething gone wrong...\n\n";
        }
        return 0;
    }
    void firstPlayerMove()
    {
        cout << "\t---1st player's move---\n";
        char getCard = 'y';
        do
        {
            firstPlayerGetsCard();
            cout << "1st player has: " << getFirstScore() << " points\n";
            if (getFirstScore() < 21)
            {
                cout << "Take one more card? (y/n):";
                cin >> getCard;
                cout << endl;
            }
            else if (getFirstScore() > 21)
                cout << "You have gone over 21\n";
            else
                cout << "Probably you will win...\n";
        } while (getCard == 'Y' || getCard == 'y' && getFirstScore() < 21);
    }
    void secondPlayerMove()
    {
        char getCard = 'y';
        cout << "\n\t---2nd player's move---\n";
        do
        {
            secondPlayerGetsCard();
            cout << "2nd player has: " << getSecondScore() << " points\n";
            if (getSecondScore() < 21)
            {
                cout << "Want another card? (y/n):";
                cin >> getCard;
                cout << endl;
            }
            else if (getSecondScore() > 21)
                cout << "You have gone over 21\n";
            else
                cout << "Perhaps you will win...\n";
        } while (getCard == 'Y' || getCard == 'y' && getSecondScore() < 21);
    }
    ~twentyone(){};
};
void finalResult(int firstScore, int secondScore)
{
    if (firstScore == secondScore)
        cout << "\t-~-~-~Draw-~-~-~\n";
    else if (firstScore > secondScore)
        cout << "\t-~-~-~1st player wins!!!~-~-~-\n";
    else
        cout << "\t-~-~-~2nd player wins!!!~-~-~-\n";
}
int main()
{
    srand(time(0));
    int firstPlayerWins = 0, secondPlayerWins = 0;
    for (size_t i = 0; i < 3; ++i)
    {
        twentyone game;
        if (i != 0)
            cout << "\t~-~-~-NEXT ROUND-~-~-~\n\n";
        game.firstPlayerMove();
        game.secondPlayerMove();
        switch (game.determineWinner())
        {
        case 1:
        {
            ++firstPlayerWins;
            break;
        }
        case 2:
        {
            ++secondPlayerWins;
            break;
        }
        }
        game.~twentyone();
        cout << "--1st player has " << firstPlayerWins << " wins - "
             << "2nd player has " << secondPlayerWins << " wins--\n\n";
    }
    finalResult(firstPlayerWins, secondPlayerWins);
}