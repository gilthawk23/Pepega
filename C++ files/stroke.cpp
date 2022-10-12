#include <iostream>
#include <ctime>
using namespace std;
class randomArray
{
    int m[5][5];

public:
    randomArray()
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                m[i][j] = rand() % 30 + 30;
            }
        }
    }
    void showArray()
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
    void findMaximumElement()
    {
        int max = 0;
        cout << endl;
        for (int j = 0; j < 5; ++j)
        {
            for (int i = 0; i < 5; ++i)
            {
                if (max < m[i][j])
                {
                    max = m[i][j];
                }
            }
            cout << max << " ";
            max = 0;
        }
    }
    void findMinimumElement()
    {
        int index, min = m[0][0];
        cout << endl << "Enter the line number: ";
        cin >> index;
        for (int i = 0; i < 5; ++i)
        {
            if (m[index][i] < min)
            {
                min = m[index][i];
            }
        }
        cout << "Minimal element: " << min << endl;
    }
};
int main()
{
    srand(time(0));
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((i == 1) || (j == 1) || (i == n) || (j == m))
            {
                cout << "* ";
            }
            else
                cout << "  ";
        }
        cout << endl;
    }

    // randomArray first;
    // first.showArray();
    // first.findMaximumElement();
    // first.findMinimumElement();
}