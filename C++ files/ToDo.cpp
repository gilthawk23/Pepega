#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    cout << "h for help\n";
    char symbol;
    do
    {
        cout << ':';
        cin >> symbol;
        switch (symbol)
        {
        case 'H':
        {
        case 'h':
        {
            cout << "Type first letter\nHelp\nRead\nWrite\nDelete line\nExit - Quit\n";
            break;
        }
        }
        case 'R':
        {
        case 'r':
        {
            string txt;
            ifstream file;
            file.open("ToDoList.txt");
            while (!file.eof())
            {
                getline(file, txt);
                if (!txt.empty())
                    cout << txt << endl;
            }

            file.close();
            break;
        }
        }
        case 'W':
        {
        case 'w':
        {
            cout << "Write something\n";
            ofstream file;
            file.open("ToDoList.txt", ios_base::app);
            string line;
            getline(cin, line);
            getline(cin, line);
            file << line << endl;
            file.close();
            break;
        }
        }
        case 'D':
        {
        case 'd':
        {
            string txt;
            vector<string> outContent;
            int i = 1, lineToDelete;
            ifstream file;
            file.open("ToDoList.txt");
            while (!file.eof())
            {
                getline(file, txt);
                if (!txt.empty())
                {
                    outContent.push_back(txt);
                    cout << i << " " << txt << endl;
                }
                ++i;
            }
            if (!outContent.empty())
            {
                cin >> lineToDelete;

                cout << "\"" << outContent[lineToDelete - 1] << "\" deleted\n";
                outContent.erase(outContent.begin() + lineToDelete - 1);
                file.close();
                ofstream sfile;
                sfile.open("ToDoList.txt");
                for (string s : outContent)
                    sfile << s << endl;
            }
            else
                cout << "ToDoList is empty\n";
            break;
        }
        }
        case 'E':
        case 'Q':
        case 'q':
        case 'e':
        default:
            symbol = 'e';
        }
    } while (symbol != 'e');
}