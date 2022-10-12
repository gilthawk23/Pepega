#include <iostream>
using namespace std;
int main()
{

    int x, y, matrix[5][5], steps[5][5] = {{4, 3, 2, 3, 4}, {3, 2, 1, 2, 3}, {2, 1, 0, 1, 2}, {3, 2, 1, 2, 3}, {4, 3, 2, 3, 4}};
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                x = j;
                y = i;
            }
        }
    }
    cout << endl
         << steps[y][x];
}