#include <iostream>
using namespace std;
int main() 
{
 cout << "Average of numbers\n";
 int n;
 int i=0;  
 double sum = 0; // sums values
 cout << "Enter number, -100 to quit: ";
 cin >> n;
  
 while (n != -100)
  { 
   sum += n; // sum = sum + n
   i++; // counter of values entered
   cout << "Enter number, -100 to quit: ";
   cin >> n;
  }

 double average;
 average = sum/i; // formula of average
 cout << "The average of all numbers you entered is " << average;
}