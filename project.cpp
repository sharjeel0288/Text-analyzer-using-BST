#include "tree.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;
void removeSpecialChars(string &word)
{
    size_t found = word.find(".");
    if (found != string::npos)
    {
        word.erase(remove(word.begin(), word.end(), '.'), word.end());
    }
    found = word.find(",");
    if (found != string::npos)
    {
        word.erase(remove(word.begin(), word.end(), ','), word.end());
    }
    found = word.find("\'");
    if (found != string::npos)
    {
        word.erase(remove(word.begin(), word.end(), '\''), word.end());
    }
    found = word.find("\"");
    if (found != string::npos)
    {
        word.erase(remove(word.begin(), word.end(), '\"'), word.end());
    }
    found = word.find(";");
    if (found != string::npos)
    {
        word.erase(remove(word.begin(), word.end(), ';'), word.end());
    }
    found = word.find(":");
    if (found != string::npos)
    {
        word.erase(remove(word.begin(), word.end(), ':'), word.end());
    }
    found = word.find("(");
    if (found != string::npos)
    {
        word.erase(remove(word.begin(), word.end(), '('), word.end());
    }
    found = word.find(")");
    if (found != string::npos)
    {
        word.erase(remove(word.begin(), word.end(), ')'), word.end());
    }
}
int main()
{
    BSTree analyzer;
    string fileName;
    cout << "Enter file NAME : ";
    cin >> fileName;
    ifstream file;
    file.open(fileName);
    if (!file.is_open())
    {
        cout << "ERROR FILE DOES NOT EXIST" << endl;
        return 0;
    }
    string word;
    while (file >> word)
    {
        size_t found = word.find(".");
        if (found != string::npos)
        {
            analyzer.incrementCount();
            // word.erase(remove(word.begin(), word.end(), '.'), word.end());
        }
        removeSpecialChars(word);
        analyzer.insertItem(word);
    }
    cout << "FILE NAME: "
         << fileName << endl
         << "******STATISTICAL SUMMARY******" << endl
         << "TOTAL NUMBER OF WORDS:  " << analyzer.WordCounter() << endl
         << "TOTAL NUMBER OF \"UNIQUE\" WORDS: " << analyzer.UniqueWordCount() << endl
         << "TOTAL NUMBER OF \"UNIQUE\" WORDS OF MORE THAN THREE LETTERS: " << analyzer.UniqueWord3Letter() << endl
         << "AVERAGE WORD LENGTH: " << analyzer.AvgWordLen() << " characters " << endl
         << "AVERAGE SENTENCE LENGTH: " << analyzer.AvgSentenceLen() << " words" << endl
         << "******STLE WARNINGS******" << endl;

    analyzer.WordUsedMore();
    int SentenceWord = analyzer.AvgSentenceLen();
    int WordLen = analyzer.AvgWordLen();
    if (SentenceWord > 10)
        cout << "AVERAGE SENTENCE LENGTH TOO LONG- " << SentenceWord << " Words" << endl;
    if (WordLen > 5)
        cout << "AVERAGE WORD LENGTH TOO LONG- " << WordLen << " characters " << endl;
    analyzer.AvgSentenceLen();

    cout << "******INDEX OF UNIQUE WORDS******" << endl;
    analyzer.PrintUniqueWords();
}