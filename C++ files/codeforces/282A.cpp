#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, x = 0;
    string sentence;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> sentence;
        if (sentence == "++X" || sentence == "X++")
            ++x;
        else if (sentence == "--X" || sentence == "X--")
            --x;
    }
    cout << x;
}