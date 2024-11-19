#include <iostream>
using namespace std;
// Assia KHADER
// ITP 165, 2022 fall
// Homework 2 Horoscope
int main() 
{

int m; 
cout << "Enter your birth month (1-12) ";
cin >> m;
int d;
cout << "Enter the day you were born on (1-31) ";
cin >> d;
  
string sign;
 if (m == 12)
  { if (d < 22)
    sign = "Sagittarius";
        else
    sign = "Capricorn";
  }
         
else if (m == 1)
  {
    if (d < 20)
    sign = "Capricorn";
    else
    sign = "Aquarius";
  }
         
else if (m == 2)
  {
    if (d < 19)
    sign = "Aquarius";
    else
    sign = "Pisces";
  }
         
else if (m == 3)
  {
    if (d < 21)
    sign = "Pisces";
    else
    sign = "Aries";
  }
else if (m == 4)
  {
    if (d < 20)
    sign = "Aries";
    else
    sign = "Taurus";
  }
         
else if (m == 5)
  {
    if (d < 21)
    sign = "Taurus";
    else
    sign = "Gemini";
  }
         
else if (m == 6)
  {
    if (d < 21)
    sign = "Gemini";
    else
    sign = "Cancer";
  }
         
else if (m == 7)
  {
    if (d < 23)
    sign = "Cancer";
    else
    sign = "Leo";
  }
         
else if (m == 8)
  {
    if (d < 23)
    sign = "Leo";
    else
    sign = "Virgo";
  }
         
else if (m == 9)
  {
    if (d < 23)
    sign = "Virgo";
    else
    sign = "libra";
  }
         
else if (m == 10)
  {
    if (d < 23)
    sign = "Libra";
    else
   sign = "Scorpio";
  }
         
else if (m == 11)
  {
    if (d < 22)
    sign = "Scorpio";
    else
    sign = "Sagittarius";
  }

string horoscope;
if (m == 12)
  { if (d < 22)
    horoscope = "You will come out from the past day’s messy situation.";
    
    else
    horoscope = "You may feel unhappy and feel like a victim of mood swings.";
  }
         
else if (m == 1)
  {
    if (d < 20)
    horoscope = "You may feel unhappy and feel like a victim of mood swings.";
    else
    horoscope = "You will spread happiness around you and feel harmony in your personal life.";
  }
         
else if (m == 2)
  {
    if (d < 19)
    horoscope = "You will spread happiness around you and feel harmony in your personal life.";
    else
    horoscope = "Your performance at work will be good and you will get some incentives in terms of rewards.";
  }
         
else if (m == 3)
  {
    if (d < 21)
    horoscope = "Your performance at work will be good and you will get some incentives in terms of rewards.";
    else
    horoscope = "You will help needy people, which will improve your reputation in society.";
  }
else if (m == 4)
  {
    if (d < 20)
    horoscope = "You will help needy people, which will improve your reputation in society.";
    else
    horoscope = "You may feel dissatisfied because you are detached from your responsibilities.";
  }
         
else if (m == 5)
  {
    if (d < 21)
    horoscope = "You may feel dissatisfied because you are detached from your responsibilities.";
    else
    horoscope = "You will be focused and work on postponed projects.";
  }
         
else if (m == 6)
  {
    if (d < 21)
    horoscope = "You will be focused and work on postponed projects.";
    else
    horoscope = "You will control your expenditure on worthless things which will increase your financial health.";
  }
         
else if (m == 7)
  {
    if (d < 23)
    horoscope = "You will control your expenditure on worthless things which will increase your financial health.";
    else
    horoscope = "You will have peace of mind which will help you balance out stress.";
  }
         
else if (m == 8)
  {
    if (d < 23)
    horoscope = "You will have peace of mind which will help you balance out stress.";
    else
    horoscope = "You may feel dull and face some old health issues.";
  }
         
else if (m == 9)
  {
    if (d < 23)
    horoscope = "You may feel dull and face some old health issues.";
    else
    horoscope = "You will feel inner strength and your losses will convert into profit.";
  }
         
else if (m == 10)
  {
    if (d < 23)
    horoscope = "You will feel inner strength and your losses will convert into profit.";
    else
   horoscope = "Your wisdom will help you make the right decisions which will boost your business.";
  }
         
else if (m == 11)
  {
    if (d < 22)
    horoscope = "Your wisdom will help you make the right decisions which will boost your business.";
    else
    horoscope = "You will come out from the past day’s messy situation.";
  }

 cout << "Your sign is " << sign;
 cout << "\nYour horoscope prediction is: " << horoscope;
}