#include <iostream>
using namespace std;
int main()
{
   
    int j, a, b, c, values[7] = {0};
    cin >> a >> b >> c;
    bool flag = false;
    const int pattern[7] = {1, 2, 3, 1, 3, 2, 1}, ac = a, bc = b, cc = c;
    for (int i = 0; i < 7; ++i)
    {
        j = i;
        while (!flag)
        {
            switch (pattern[j])
            {
            case 1:
            {
                if (a != 0)
                {
                    --a;
                    ++values[i];
                }
                else
                    flag = true;
                break;
            }
            case 2:
            {
                if (b != 0)
                {
                    --b;
                    ++values[i];
                }
                else
                    flag = true;
                break;
            }
            case 3:
            {
                if (c != 0)
                {
                    --c;
                    ++values[i];
                }
                else
                    flag = true;
                break;
            }
            }
            if (j == 6)
                j = i;
            else
                ++j;
        }
        flag = false;
        a = ac;
        b = bc;
        c = cc;
    }

    for (int i = 0; i < 7; ++i)
    {
        cout << values[i] << " ";
    }
}
