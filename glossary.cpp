// Assia Khader
// ITP 165, 2023 Spring
// Gloss

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Struct to hold the dictionary information for a word
struct WordInfo 
{
    string word;
    int freq;
    int counter;
    float ratio;
};

// Function to clean words (removes punctuation) from text file
string cleanWord(string word) 
{
    string cleanedWord = "";
    for (int i = 0; i < word.length(); i++) 
    {
        if (isalpha(word[i])) 
        {
            cleanedWord += tolower(word[i]);
        }
    }
    return cleanedWord;
}

// Function to find and count a single word in the dictionary
void findAndCountWord(string word, vector<WordInfo>& dictionary) 
{
    string cleanedWord = cleanWord(word);
    for (int i = 0; i < dictionary.size(); i++) {
        if (dictionary[i].word == cleanedWord) 
        {
            dictionary[i].counter++;
            break;
        }
    }
}

// Function to read dictionary file and fill the vector of structs
void readDictionaryFile(string fileName, vector<WordInfo>& dictionary) 
{
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) 
    {
        cout << "Error opening file" << endl;
        return;
    }

    string word;
    while (inputFile >> word) 
    {
        word = cleanWord(word);
        if (word != "") 
        {
            bool wordFound = false;
            for (int i = 0; i < dictionary.size(); i++) 
            {
                if (dictionary[i].word == word)
                {
                    dictionary[i].freq++;
                    wordFound = true;
                    break;
                }
            }
            if (!wordFound) 
            {
                WordInfo newWordInfo;
                newWordInfo.word = word;
                newWordInfo.freq = 1;
                newWordInfo.counter = 0;
                newWordInfo.ratio = 0.0f;
                dictionary.push_back(newWordInfo);
            }
        }
    }

    inputFile.close();
}

// Function to compute the ratio of word counts to the normal frequencies
void computeRatios(vector<WordInfo>& dictionary, int totalWords) 
{
    for (int i = 0; i < dictionary.size(); i++) {
        dictionary[i].ratio = ((float)dictionary[i].counter / totalWords) / dictionary[i].freq;
    }
}

// Function to find and print the words with the highest ratios
void printTopWords(vector<WordInfo>& dictionary) {
    cout << "The top 25 words in the text are:\n";
    for (int j = 0; j < 25; j++) 
    {
        int maxIndex = 0;
        for (int i = 1; i < dictionary.size(); i++) 
        {
            if (dictionary[i].ratio > dictionary[maxIndex].ratio) 
            {
                maxIndex = i;
            }
        }
        float freqPercent = dictionary[maxIndex].ratio * 100;
        cout << j + 1 << ". " << dictionary[maxIndex].word << " (" << freqPercent << "%)" << endl;
        dictionary[maxIndex].ratio = 0;
    }
}

// Function to reset the counts
void resetCounts(vector<WordInfo>& dictionary) 
{
    for (int i = 0; i < dictionary.size(); i++) 
    {
        dictionary[i].counter = 0;
    }
}

// Main function
int main() 
{
    vector<WordInfo> dictionary;
    string dictionaryFileName = "DictAnd.txt";
    readDictionaryFile(dictionaryFileName, dictionary);

    string fileName;
    do 
    {
        cout << "Enter a file name (or 'quit' to quit): ";
        cin >> fileName;

    if (fileName != "quit") 
    {
        ifstream inputFile(fileName);
        if (!inputFile.is_open()) 
        {
            cout << "Error opening file: " << fileName << endl;
            continue;
        }

        int totalWords = 0;
        string word;
        while (inputFile >> word) 
        {
            findAndCountWord(word, dictionary);
            totalWords++;
        }
        inputFile.close();

        computeRatios(dictionary, totalWords);

printTopWords(dictionary);
resetCounts(dictionary);
    } 
  }
  while (fileName != "quit");

return 0;
}