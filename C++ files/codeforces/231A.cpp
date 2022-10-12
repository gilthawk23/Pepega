#include <iostream>
using namespace std;
int main()
{
    int N, count = 0, temp = 0;
    bool arr[3];
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> arr[j];
            if (temp >= 2)
            {
                ++count;
                temp = 0;
                break;
            }
            if (arr[j] == 1)
                ++temp;
        }
    }
    cout << count << endl;
}
