#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
ofstream file;
const char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!;%:?*()_+@#$^&abcdefghijklmnopqrstuvwxyz<>"; // символы которые может содержать пароль
const int filech = 10;                                                                                      // кол-во символов в пароле
const char fileName[] = "pass.txt";                                                                         // имя файла для вывода
void print(int count, string str = "")
{
    for (int i = 0; symbols[i]; i++)
    {
        string temp(str);
        temp += symbols[i];

        if (count > 1)
            print(count - 1, temp);
        else
        {
            cout << temp << endl;
            if (temp == "qE90(J1o8c")
            {
                cout << "Success" << endl;
                exit(0);
            }
        }
    }
}
int main()
{
    srand(time(0));
    const string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!;%:?*()_+@#$^&abcdefghijklmnopqrstuvwxyz<>";
    const int length = symbols.length();
    int amountofpswrds = 15;
    while (amountofpswrds)
    {
        for (int i = 0; i < filech; ++i)
            cout << symbols[rand() % length];
        cout << endl;
        --amountofpswrds;
    }
}