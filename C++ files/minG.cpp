/*
Необходимо найти строку, содержащую наименьшее количество букв G 
(если таких строк несколько, надо взять ту, которая находится в файле раньше), 
и определить, какая буква встречается в этой строке чаще всего. 
Если таких букв несколько, надо взять ту, которая позже стоит в алфавите.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    // settings
        string path = "24_5.txt";
    //
    ifstream in;
    in.open(path);
    string txt;
    int frequency[26] = {0}, counter = 0, index = 0, indexG = 0, minG = INT_MAX;
    while (!in.eof())
    {
        index++;
        getline(in, txt);
        if (!txt.empty())
        {
            for (int i = 0; i < txt.length(); ++i)
            {
                if (txt[i] == 'G')
                {
                    ++counter;
                }
            }
            if (counter < minG)
            {
                minG = counter;
                indexG = index;
            }
            counter = 0;
        }
    }
    index = 0;
    cout << indexG << endl;
    in.close();
    in.open(path);
    if (minG != INT_MAX)
    {
        while (index != indexG)
        {
            ++index;
            getline(in, txt);
        }
        cout << txt << endl;
    }
    for (int i = 0; i < txt.length(); ++i)
    {
        ++frequency[txt[i] - 'A'];
    }
    char symbol = 'A', result;
    int max = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (frequency[i] != 0)
        {
            cout << frequency[i] << " " << symbol << endl;

            if (max < frequency[i])
            {
                max = frequency[i];
                result = symbol;
            }
            else if (max == frequency[i])
            {
                if (result < symbol)
                {
                    result = symbol;
                }
            }
        }
        ++symbol;
    }
    cout << result << endl;
}