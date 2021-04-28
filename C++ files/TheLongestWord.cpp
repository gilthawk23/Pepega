#include <iostream>
#include <string>
using namespace std;
int main()
{
    string txt, word, longestWord;
    int sum = 0, maxsum = 0;
    getline(cin, txt);
    for (int i = 0; i < txt.length(); ++i)
    {
        if (txt[i] != ' ')
        {
            sum++;
            word += txt[i];
        }
        if ((txt[i] == ' ') || (i == txt.length() - 1))
        {
            if (sum > maxsum)
            {
                maxsum = sum;
                longestWord = word;
            }
            sum = 0;
            word = ""s;
        }
    }
    cout << endl
         << "\""s << longestWord << "\""s
         << " : "s << maxsum << endl;
}