#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
   int n = 0;
   while (n != -1)
   {
    cout << "enter non-negative number: ";
    cin >> n;
    if (n!=100 && n>0)
    {
    cout << sqrt(n) << endl;
    } 
    else if (n==100)
    {
    cout << "wow"<< endl;
    }
  }
  return 0; 
}