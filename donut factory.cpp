#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Assia Khader
// ITP 165, 2022 fall 
// Homework 01 Donut

int main() {
  
  cout << "Welcome to the Bakery!\n";//trivial print
  cout << "The price of a donut is 2.70 dollars\n";
  cout <<"Adding sprinkles costs 0.35 dollars\n";
string name;//string because sequence of characters
cout <<"What is your name? \n";
cin >>name;//customer's name
int donut;//int because whole number
cout <<"How many donuts do you want?\n";
cin >>donut;
int sprinkles;//int because whole number
cout <<"How many with sprinkles? \n";//n for new line
cin >>sprinkles;

double priceDonut = 2.70;//unit price of one donut
  //double because number with decimal
double priceSprinkles = 0.35;//unit price of donut with sprinkles
double price = (donut * priceDonut) + (sprinkles * priceSprinkles);//compute price of order

  
cout << name <<", your "<<donut  <<" donuts with "<<sprinkles  <<" sprinkles costs "<<price<< " dollars" <<endl;
  
return 0;
}