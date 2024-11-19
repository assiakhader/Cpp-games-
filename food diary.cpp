#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

//A struct representing a single day in the diary 
struct Day 
{
    string date;              //date of the day
    vector<string> foods;     //foods eaten on the day
    vector<string> feelings;  //feelings experienced on the day
};

//Function to add a string to a vector if it's not already in the vector
void addUnique(vector<string>* v, string s); 

//Function to check if a string is already in a vector
bool contains(vector<string>* v, string s);

//Function to get the Day struct for a particular date, creating it if necessary
Day* getDay(string d, vector<Day*>& days);

//Function to analyze a single pair of (food, feeling) across all days
void analyzeOnePair(string food, string feeling, vector<Day*>& days, vector<string>* foods, vector<string>* feelings); 

//Function to analyze all pairs of (food, feeling) and print out any that happen at least half the time
void analyze(vector<Day*>& days, vector<string>* foods, vector<string>* feelings);

//Function to delete all memory allocated by the program and clear out all vectors
void clear(vector<Day*>& days, vector<string>* foods, vector<string>* feelings);

//Function to read in the diary from a file and populate the vectors of days, foods, and feelings
void readDiary(string filename, vector<Day*>& days, vector<string>* foods, vector<string>* feelings);

//Main function
int main() 
{

    vector<string> foods;     //master list of foods
    vector<string> feelings;  //master list of feelings
    vector<Day*> days;        //vector of pointers to Day structs

    string filename;
    int choice;
  //menu
    do 
    {
        cout << "Welcome to the Food Diary program.\n";
        cout << "0: quit\n";
        cout << "1: read diary file\n";
        cout << "2: analyze data\n";
        cout << "3: clear data\n";
        cout << "choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 0:
                clear(days, &foods, &feelings);
                cout << "Goodbye!\n";
                break;
            case 1:
                 readDiary(filename, days, &foods, &feelings);
                break;
            case 2:
                analyze(days, &foods, &feelings);
                break;
            case 3:
                clear(days, &foods, &feelings);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } 
  while (choice != 0);
  return 0;
}


void addUnique(vector<string>* v, string s)
{
    //calls contains() to check if vector v contains string s
     if (!contains(v, s))
     {
      //if s is not already in v, add s to the vector pointed to by v
       v->push_back(s);
     }  
}


bool contains(vector<string>* v, string s) 
{
  //compares each element in vector v to string s
    for (auto it = v->begin(); it != v->end(); ++it) 
    {
        if (*it == s) 
        {
          //return true if s contained in v
            return true;
        }
    }
  //return false if s not contained in v
    return false;
}

Day* getDay(string d, vector<Day*>& days) 
{
    for (auto it = days.begin(); it != days.end(); ++it) 
    {
        if ((*it)->date == d) 
        {
          //return a pointer to the Day struct for this date
            return *it;
        }
    }
  //if  given date not on vector, make a new day using dynamic allocation
    Day* newDay = new Day();
    newDay->date = d;
    days.push_back(newDay);
    return newDay;
}


void analyzeOnePair(string food, string feeling, vector<Day*>& days, vector<string>* foods, vector<string>* feelings) 
{
    int numFoods = 0;
    int numFoodFeelings = 0;
    for (auto it = days.begin(); it != days.end(); ++it) 
    {
        if (contains(&((*it)->foods), food)) 
        {
          //given a food and feeling, count the days you ate it and got the feeling
            numFoods++;
            if (contains(&((*it)->feelings), feeling)) 
            {
                numFoodFeelings++;
            }
        }
    }
  //compute the ratio (a conditional probability)
    double ratio = (double) numFoodFeelings / (double) numFoods;
    if (ratio >= 0.5) 
    {
      //print if more than 0.5
        cout << food << " causes " << feeling << endl;
    }
}


//double nested loop that calls analyzeOnePair() on every possible food and feeling combination
void analyze(vector<Day*>& days, vector<string>* foods, vector<string>* feelings) 
{
  //one loop goes through the master food vector
    for (auto it = foods->begin(); it != foods->end(); ++it) 
    {
      //one loop goes through the master feeling vector
        for (auto jt = feelings->begin(); jt != feelings->end(); ++jt) 
        {
            analyzeOnePair(*it, *jt, days, foods, feelings);
        }
    }
}

 
void clear(vector<Day*>& days, vector<string>* foods, vector<string>* feelings) 
{
    for (auto it = days.begin(); it != days.end(); ++it) 
    {
      //deallocate anything that was dynamically allocated
        delete *it;
    }
  //clear all of the vectors
    days.clear();
    foods->clear();
    feelings->clear();
}


void readDiary(string filename, vector<Day*>& days, vector<string>* foods, vector<string>* feelings) 
{
  //read and parse the file entered
    cout << "Enter the filename of your diary: ";
    cin >> filename;
    ifstream infile(filename);
    string line;
    int numLines = 0;
    while (getline(infile, line)) 
    {
        numLines++;
      //check if line starts with "food"
        if (line.substr(0, 4) == "food") 
        {
          //extracts word between "food" and the date
            size_t foodStart = line.find(" ") + 1;
            size_t foodEnd = line.find(" ", foodStart);
            string food = line.substr(foodStart, foodEnd - foodStart);
          //adds given food to master food vector
            addUnique(foods, food);
          //gets day for food and adds it to the day's food vector
            Day* day = getDay(line.substr(foodEnd + 1), days);
            day->foods.push_back(food);
        } 
      //check if line starts with "feeling"
        else if (line.substr(0, 8) == "feeling ") 
        {
          //extracts word between "feeling" and the date
            size_t feelingStart = line.find(" ") + 1;
            size_t feelingEnd = line.find(" ", feelingStart);
            string feeling = line.substr(feelingStart, feelingEnd - feelingStart);
          //adds given feeling to master feeling vector
            addUnique(feelings, feeling);
          //gets day for feeling and adds it to the day's feeling vector
            Day* day = getDay(line.substr(feelingEnd + 1), days);
            day->feelings.push_back(feeling);
        }
    }
  //prints number of lines read from file
    cout << numLines << " lines of data read" << endl;
}
