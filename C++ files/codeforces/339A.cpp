#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<char> result;
    string sentence;
    cin >> sentence;
    for (char ch : sentence)
    {
        if (isdigit(ch))
            result.push_back(ch);
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i)
    {
        if (i == result.size() - 1)
            cout << result[i];
        else
            cout << result[i] << "+";
    }
}