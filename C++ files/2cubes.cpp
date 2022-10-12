#include <iostream>
#include <ctime>
using namespace std;
int firstUserThrow()
{
    int cube1 = rand() % 6 + 1, cube2 = rand() % 6 + 1;
    cout << "Computer\n |" << cube1 << "| |" << cube2 << "|\n";
    return cube1 + cube2;
}
int secondUserThrow()
{
    int cube1 = rand() % 6 + 1, cube2 = rand() % 6 + 1;
    cout << "User\n |" << cube1 << "| |" << cube2 << "|\n";
    return cube1 + cube2;
}
void showScore(int computerScore, int userScore)
{
    cout << "Computer: " << computerScore << "  User:" << userScore << endl
         << endl;
}
void whoWin(int computerScore, int userScore)
{
    if (computerScore == userScore)
        cout << "==\n";
    else if (computerScore > userScore)
        cout << "Computer win!\n";
    else
        cout << "User win!\n";
}
int main()
{
    int computerScore = 0, userScore = 0;
    srand(time(0));
    if (rand() % 2) // computer
    {
        for (int i = 0; i < 4; ++i)
        {
            computerScore += firstUserThrow();
            userScore += secondUserThrow();
            showScore(computerScore, userScore);
        }
        whoWin(computerScore, userScore);
    }
    else // user
    {
        for (int i = 0; i < 4; ++i)
        {
            userScore += secondUserThrow();
            computerScore += firstUserThrow();
            showScore(computerScore, userScore);
        }
        whoWin(computerScore, userScore);
    }
}