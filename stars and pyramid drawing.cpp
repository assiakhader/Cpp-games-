#include <iostream>
using namespace std;
int main() 
{
  
//stars 
  
 int n;
 cout<< "Enter n: ";
 cin>> n; 
 
 for ( int i = 1; i <= n; i++)
  {
  cout << "*" ;
  }
 cout << endl;
  
  
//pyramid 
  
 int line;
 cout << "Enter n: ";
 cin >> line;

 for(int i = 1; i <= line; i++) 
  {
  for(int j = 1; j <= i; j++) 
    {
    cout << "* ";
    }
  cout << "\n";
  }
 cout << endl;
}

