#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int N, count = 0;
    string temp, word = "";
    vector<string> out;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        if (temp.length() > 10)
        {
            count = 0;
            word = "";
            for (int j = 0; j < temp.length(); ++j)
            {
                if (j == 0)
                {
                    word += temp[j];
                }
                else if (j == temp.length() - 1)
                {
                    word += to_string(count);
                    word += temp[j];
                }
                else
                    ++count;
            }
            out.push_back(word);
        }
        else
            out.push_back(temp);
    }
    for (string s : out)
    {
        cout << s << endl;
    }
}