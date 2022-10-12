#include <iostream>
#include <string>
using namespace std;
int main()
{
    int ints1 = 0, ints2 = 0;
    string s1, s2;
    cin >> s1 >> s2;
    for (char ch : s1)
    {
        if (isupper(ch))
            ch = tolower(ch);
        ints1 += ch;
    }
    for (char ch : s2)
    {
        if (isupper(ch))
            ch = tolower(ch);
        ints2 += ch;
    }
    if (ints1 == ints2)
        cout << 0;
    else if (ints1 > ints2)
        cout << 1;
    else if (ints1 < ints2)
        cout << -1;
}