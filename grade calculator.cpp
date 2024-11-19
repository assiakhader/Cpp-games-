
#include <iostream>
#include <vector>
using namespace std;
// Assia Khader
// ITP 165, 2023 spring 
// Gradebook vector 

void avgGrade(vector<double>& grades);
void print(vector<double>& grades);
void removeGrade(vector<double>& grades);
void clearVec(vector<double>& grades);
void gradeEntry(vector<double>& grades);

// Function prints vector of grades
// v - parameter vector <double>
//return 

int main() 
{

  cout << "Grade Book\n";

    vector<double> grades;
    int choice;
  
  while (choice !=0) 
  {
    cout << "1. Print grades" << endl;
    cout << "2. Add grade" << endl;
    cout << "3. Print average" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter choice: \n";
    cin >> choice;
    
    if (choice == 1)
    {
        print(grades);
    }
    if (choice == 2)
    {
        gradeEntry(grades);
    }

    if (choice == 3)
    {
        avgGrade(grades);
    }
    if (choice == 4)
    {
        clearVec(grades);
    }
 }
    return 0;
}

void gradeEntry(vector<double>& grades)
{
    double grade;
    cout << "Enter Grades (or -1 to end): " << endl;
    cin >> grade;
    while (grade != -1)
    {
        grades.push_back(grade);
        cin >> grade;
    }
}

void avgGrade(vector<double>& grades)
{
    double sum = 0;
    double average = 0;
    {
        for (int i = 0; i<grades.size(); i++)
        {sum += grades[i];}
        average = (sum/grades.size());
        cout << "Average Grade: " << average << endl;
    }
}

void clearVec(vector<double>& grades)
{
    grades.clear();
}

void print(vector<double>& grades) {
    cout << "Grades: " << endl;
    for (int j = 0; j < grades.size(); j++) { cout << (j+1) << ". " << grades[j] << endl; }
    cout << endl;
}