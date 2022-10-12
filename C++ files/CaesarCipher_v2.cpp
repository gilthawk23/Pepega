#include <iostream>
#include <string>
using namespace std;
string encryptCaesar(string txt, const int d)
{
    string result = "";
    for (size_t i = 0; i < txt.length(); ++i)
    {
        if (txt[i] != ' ')
        {
            if (isupper(txt[i]))
            {
                result += char(int(txt[i] + d - 65) % 26 + 65);
            }
            else
            {
                result += char(int(txt[i] + d - 97) % 26 + 97);
            }
        }
        else
            result += " ";
    }
    return result;
}

int main()
{
    string sentence;
    const int d = 1;
    getline(cin, sentence);
    cout << encryptCaesar(sentence, d) << endl;
}