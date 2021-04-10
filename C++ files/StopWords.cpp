#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <chrono>
using namespace std;

vector<string> SplitIntoWords(string text)
{
    vector<string> words;
    string word;
    for (int i = 0; i < text.size(); ++i)
    {
        if (text[i] == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word += text[i];
        }
    }

    words.push_back(word);

    return words;
}

set<string> MakeSet(vector<string> query_words)
{
    set<string> s(query_words.begin(), query_words.end());
    return s;
}

int main()
{
    bool ex = 0;
    string query, StopWords;
    getline(cin, StopWords);
    SplitIntoWords(StopWords);
    getline(cin,query);

    auto start = chrono::high_resolution_clock::now();

    for (string word : SplitIntoWords(query))
    {
        for (string stopword : MakeSet(SplitIntoWords(StopWords)))
        {
            if (stopword == word)
            {
                ex = 1;
                break;
            }
            else if (stopword != word)
            {
                ex = 0;
            }
        }
        if (ex == 0)
        {
            cout << '[' << word << ']' << endl;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Duration: \t" << duration.count() << endl;
}