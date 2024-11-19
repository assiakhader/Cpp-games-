#include <iostream>
#include <cmath>
using namespace std;

void roof();
void topWindow();
void middleWindow();
void bottomWindow();
void door();
void floor();

int main() 
{ 
  roof();
  topWindow();
  middleWindow();
  bottomWindow();
  door();
  floor();
}

void roof()
{
  cout<<"|============================|"<<endl;
  cout<<"|                            |"<<endl;
}

void topWindow()
{
  cout<<"|    --      --      --      |"<<endl;
  cout<<"|   |  |    |  |    |  |     |"<<endl;
  cout<<"|   |  |    |  |    |  |     |"<<endl;
}


void middleWindow()
{
cout <<"|                            |"<<endl;
cout <<"|    --      --      --      |"<<endl;
cout <<"|   |  |    |  |    |  |     |"<<endl;
cout <<"|   ====    ====    ====     |"<<endl;
cout <<"|                            |"<<endl;
cout <<"|                            |"<<endl;
cout <<"|    --      --      --      |"<<endl;
cout <<"|   |  |    |  |    |  |     |"<<endl;
cout <<"|   ====    ====    ====     |"<<endl;
cout <<"|                            |"<<endl;
}


void bottomWindow()
{
cout <<"|                            |"<<endl;
cout <<"|    **      **      **      |"<<endl;
cout <<"|   *  *    *  *    *  *     |"<<endl;
cout <<"|    **      **      **      |"<<endl;
cout <<"|                            |"<<endl;
cout <<"|                            |"<<endl;
}

void door()
{
cout <<"|          ======            |"<<endl;
cout <<"|          |    |            |"<<endl;
cout <<"|          |  + |            |"<<endl;
cout <<"|          |    |            |"<<endl;
} 

void floor()
{ 
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

