// swap
/* 
template <class T>
void swap (T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = *temp;
} 
*/

// from string to vector
/* 
vector<string> SplitIntoWords(const string& text)
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
*/

// Selection sort
/* 
// main
const int size = 10;
int arr[size];
char direction;
cin >> direction;
SelectionSort(arr, direction, size);

void SelectionSort(int *arr, const char direction, const int size)
{
    int min = 0;
    int temp = 0;

    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (direction == '<')
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            else if (direction == '>')
            {
                if (arr[j] > arr[min])
                {
                    min = j;
                }
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
*/

// duration
/* 
auto start = chrono::high_resolution_clock::now();
                    // code // 
auto end = chrono::high_resolution_clock::now();
chrono::duration<double> duration = end - start; 
*/

// info
/* 
При использовании функции void дописывать к параметрам ссылки. 
Иначе будет происходить все манипуляции в переменных функции, а не main 
*/

// Добавление элементов из одного вектора в другой
/* 
void MoveStrings(vector<string> &source, vector<string> &destination)
{
    for (string &word : source)
    {
        destination.push_back(word);
    }
    source.clear();
} 
*/

// info
/* 
string ReadString()
{
    string query;
    getline(cin, query);
    return query;
}
//
const string query = ReadString(); 
*/

// print map
/*
#include <map>
map <string, int> variable_name = {{"string"s, int},{"string"s, int} ...}

void PrintMap(const map<!!!> &leg_count)
{
    for (const auto &[key, value] : leg_count)
    {
        cout << key << " " << value << endl;
    }
}
*/

// output
/*  
    #include <fstream>
    ofstream fout("txt_name.txt", ios_base::app);
    fout (<<||>>) ... 
*/