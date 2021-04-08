#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

// определяет, будет ли строка s палиндромом
vector<string> SplitIntoWords(string txt)
{
	string word;
	vector<string> words;
	for (int i = 0; i < txt.size(); ++i)
	{
		if (txt[i] == ',')
		{
			words.push_back(word);
			word = ""s;
		}
		else
		{
			if (txt[i] != ' ')
			{
				word += txt[i];
			}
		}
	}
	words.push_back(word);
	return words;
}

vector<string> PalindromeFilter(vector<string> words, int min_length)
{
	int k;
	bool palindrome = 0;
	vector<string> newwords;
	// формирует и возвращает вектор подходящих палиндромов

	for (string word : words)
	{
		if (word.size() != 0)
		{
			k = word.size() - 1;
			for (int i = 0; i < word.size(); ++i)
			{
				if (word[i] == word[k])
				{
					palindrome = 1;
				}
				else
				{
					palindrome = 0; break;
				}
				k--;
			}
			if ((word.size() >= min_length) && (palindrome == 1))
			{
				newwords.push_back(word);
			}
		}
		else if (word.size()==0)
		{
			newwords.push_back(word);
		}
	}
	return newwords;
}

int main()
{
	string name;
	getline(cin, name);
	SplitIntoWords(name);
	int lenght;
	cin >> lenght;
	PalindromeFilter(SplitIntoWords(name), lenght);

	for (string word : PalindromeFilter(SplitIntoWords(name), lenght))
	{
		cout << word << endl;
	}
}