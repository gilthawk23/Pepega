#include <iostream>
#include <ctime>
#include <string>
using namespace std;
string showItem(int index)
{
    switch (index)
    {
    case 1:
    {
        return "paper";
        break;
    }
    case 2:
    {
        return "scissors";
        break;
    }
    case 3:
    {
        return "rock";
        break;
    }
    }
}
int secondPlayerMove()
{
    int itemIndex = rand() % 3 + 1;
    cout << "2nd player: ";
    cout << showItem(itemIndex) << endl;
    return itemIndex;
}
int firstPlayerMove()
{
    int itemIndex = rand() % 3 + 1;
    cout << "1st player: ";
    cout << showItem(itemIndex) << endl;
    return itemIndex;
}
int whoWin(int second = secondPlayerMove(), int first = firstPlayerMove())
{
    if (first == second)
    {
        cout << "~draw\n";
        return 0;
    }
    else if (first == 1 && second == 3)
    {
        cout << "~paper beats rock\n";
        return 1;
    }
    else if (second == 1 && first == 3)
    {
        cout << "~paper beats rock\n";
        return 2;
    }
    else
    {
        if (second > first)
        {
            cout << "~" << showItem(second) << " beats " << showItem(first) << endl;
            return 2;
        }
        else
        {
            cout << "~" << showItem(first) << " beats " << showItem(second) << endl;
            return 1;
        }
    }
}
void showScore(int firstScore, int secondScore)
{
    cout << "\t1st player: " << firstScore << "\n\t2nd player: " << secondScore << endl;
}
void plusSocialCreditPowerfulXi(int index, int &firstScore, int &secondScore)
{
    switch (index)
    {
    case 0:
    {
        firstScore += 5;
        secondScore += 5;
        showScore(firstScore, secondScore);
        break;
    }
    case 1:
    {
        firstScore += 10;
        showScore(firstScore, secondScore);
        break;
    }
    case 2:
    {
        secondScore += 10;
        showScore(firstScore, secondScore);
        break;
    }
    }
}
int main()
{
    int firstPlayerScore = 0, secondPlayerScore = 0;
    srand(time(0));
    for (int i = 0; i < 3; ++i)
    {
        plusSocialCreditPowerfulXi(whoWin(), firstPlayerScore, secondPlayerScore);
        cout << endl;
    }
    cout << "\nWinner: ";
    if (firstPlayerScore == secondPlayerScore)
        cout << "nobody!\n";
    else if (firstPlayerScore > secondPlayerScore)
        cout << "1st player!\n";
    else
        cout << "2nd player!\n";
}