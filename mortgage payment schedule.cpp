//Assia KHADER
//ITP 165,2023 Spring
//Homework 3 Mortgage
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
  //inputs - declare variables
  double 
  loan,downpayment,interest,payment,rate,insurance,houseprice;
  int month=1;
  
  //asking user to assign values to variables
  cout<<"Mortgage Payment Schedule\n";
  cout<<"Enter house price : ";
  cin>>houseprice;
  cout<<"Enter down payment : ";
  cin>>downpayment;
  cout<<"Enter interest rate %: ";
  cin>>rate;
  cout<<"Enter monthly payment : ";
  cin>>payment;
  loan = houseprice - downpayment;

  //formatting header of mortgage payment schedule
  cout<<left<<setw(9)<<setfill(' ')<<"month:";
  cout<<left<<setw(11)<<setfill(' ')<<"principle($)";
  cout<<left<<setw(4)<<setfill(' ')<<"+";    
  cout<<left<<setw(10)<<setfill(' ')<<"interest($)";
  cout<<left<<setw(4)<<setfill(' ')<<"+";
  cout<<left<<setw(12)<<setfill(' ')<<"insurance($)";
  cout<<left<<setw(4)<<setfill(' ')<<"-";
  cout<<left<<setw(12)<<setfill(' ')<<"payment($)";
  cout<<left<<setw(4)<<setfill(' ')<<"=";
  cout<<left<<setw(20)<<setfill(' ')<<"new principle($)"<<endl;
  
  //while loop
  while(loan>0)
  {
    //calculating interest and insurance
    interest = loan*(rate/1200);
      if (loan>houseprice*0.8)
      {
      insurance = 0.005/loan*12;
      }
      else
      {
      insurance=0;
      }
     

    //printing output
    cout<<left<<setw(9)<<setfill(' ') <<fixed<<setprecision(2)<<month;
    cout<<left<<setw(11)<<setfill(' ')<<fixed<<setprecision(2)<<loan;
    cout<<left<<setw(4)<<setfill(' ') <<"+";
    cout<<left<<setw(10)<<setfill(' ')<<fixed<<setprecision(2)<<interest;
    cout<<left<<setw(4)<<setfill(' ') <<"+";
    cout<<left<<setw(12)<<setfill(' ')<<fixed<<setprecision(2)<<insurance;
    cout<<left<<setw(4)<<setfill(' ') <<"-";
    cout<<left<<setw(12)<<setfill(' ')<<fixed<<setprecision(2)<<payment;
    cout<<left<<setw(4)<<setfill(' ') <<"=";
  
    //calculating new price
    loan = loan + interest + insurance - payment;
      if(loan<0)
      {
      loan=0;
      }
    cout<<fixed<<setprecision(2)<<loan<<endl;
    month++;
    }

 //printing result 
 cout << "It will take " << month << " months for the loan to be paid.";

 return 0;
}

