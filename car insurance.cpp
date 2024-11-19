#include <iostream>
using namespace std;

int main() {
  double premium = 900;


  double driverAge;
  cout << "What is your age? ";
  cin >> driverAge;
  if (driverAge < 25)
    {premium = premium + 100;}
  
  double driverHistory;
  cout << "How many years have you been driving for? ";
  cin >> driverHistory;
  if (driverHistory < 5)
    {premium = premium + 100;}


  double driverAccidents;
  cout << "How many accidents have you had in the past 5 years? ";
  cin >> driverAccidents;
  if (driverAccidents >= 1)
    {premium = premium + 100;}

  double driverCar;
  cout << "How many years old is your car? ";
  cin >> driverCar;
  if (driverCar > 5)
    {premium = premium + 100;}
  
  cout << "Your insurance is " << premium; 
return 0;
}