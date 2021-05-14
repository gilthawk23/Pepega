#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    string path = "24.txt";
    ifstream file;
    file.open(path);
    string sentence;
    file >> sentence;
    file.close();
    int letters[26];
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        letters[i] = 0;
    }
    for (int i = 0; i <= sentence.length(); ++i)
    {
        if (sentence[i - 1] == sentence[i - 2])
        {
            ++letters[int(sentence[i])];
        }
    }
    cout << endl;
    int index, max = 0;
    for (int i = 'A'; i <= 'Z'; ++i)
    {
        if (letters[i] > max)
        {
            max = letters[i];
            index = i;
        }
        cout << char(i) << " " << letters[i] << endl;
    }
    cout << endl
         << "Result\n"
         << max << " " << char(index);
}