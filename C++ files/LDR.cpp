/* 
Текстовый файл состоит не более чем из 106 символов L, D и R. 
Определите максимальную длину цепочки вида LDRLDRLDR... 
(составленной из фрагментов LDR, последний фрагмент может быть неполным).
*/
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;
void func(int &max, int &counter)
{
    if (max < counter)
    {
        max = counter;
    }
    counter = 1;
}
int main()
{
    const string path = "zadanie24_2.txt";
    string s;
    ifstream file;
    file.open(path);
    file >> s;
    file.close();
    int counter = 0, max = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (((s[i] == 'L') && (counter % 3 == 0)) || ((s[i] == 'D') && (counter % 3 == 1)) || ((s[i] == 'R') && (counter % 3 == 2)))
        {
            ++counter;
        }
        else
        {
            func(max, counter);
        }
    }
    func(max, counter);
    cout << max << endl;
}