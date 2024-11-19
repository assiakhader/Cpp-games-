// Assia KHADER
// ITP 165, 2023 spring
// Pancakes

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// function "printStack" takes a vector of integers (representing the stack of pancakes) and prints them graphically (using 'X' characters)

void printStack(vector<int> pancakes) 
{
    for (int i = 0; i < pancakes.size(); i++) 
    {
        for (int j = 0; j < pancakes[i]; j++) 
        {
            cout << "X";
        }
        cout << endl;
    }
}

// function "isSorted" takes a vector of integers and checks if it is sorted in ascending order (from smallest to largest)

bool isSorted(vector<int> pancakes) 
{
    for (int i = 0; i < pancakes.size() - 1; i++) 
    {
        if (pancakes[i] > pancakes[i + 1]) 
        {
            return false;
        }
    }
    return true;
}
 

// function "flip" flips the sub-stack of pancakes from the bottom (index 0) to the pancake at the given index, inclusive

void flip(vector<int>& pancakes, int index) 
{
  // function uses two variables left and right to keep track of the indices of the sub-stack
    int left = 0;
    int right = index;
    // while loop to swap the pancakes: increments left and decrements right until the entire sub-stack has been flipped
    while (left < right) 
    {
        int temp = pancakes[left];
        pancakes[left] = pancakes[right];
        pancakes[right] = temp;
        left++;
        right--;
    }
}

int main() 
{
    // function "srand(time(NULL))" sets the seed for the random number generator rand() with a value that depends on the current time, making the sequence of numbers different each time
  
    srand(time(NULL));
    int choice = 1;
    while (choice != 0) 
    {
        cout << "Welcome to Pancake Flipping." << endl;
        cout << "How many pancakes do you want? (2-20): ";
        int numPancakes;
        cin >> numPancakes;

        // Create a stack of pancakes in order
        vector<int> pancakes(numPancakes);
        for (int i = 0; i < numPancakes; i++) 
        {
            pancakes[i] = i + 1;
        }

        // Shuffle the stack by making random swaps
        for (int i = 0; i < numPancakes; i++) 
        {
            int j = rand() % numPancakes;
            int temp = pancakes[i];
            pancakes[i] = pancakes[j];
            pancakes[j] = temp;
        }

        // loop that asks user to enter flip point, and flips the stack of pancakes accordingly until the stack is sorted in ascending order
      
        printStack(pancakes); // print the current stack of pancakes
        int flips = 0;
        while (!isSorted(pancakes)) // while loop that repeats until the function isSorted(pancakes) returns true, meaning that the stack is sorted in ascending order
        {
            cout << "flip point (1-" << numPancakes << ")? ";
            int index;
            cin >> index;
            flip(pancakes, index - 1); // flip the sub-stack of pancakes from the bottom (index 0) to the pancake at the given index, inclusive. this modifies the input vector pancakes
            printStack(pancakes); // print the updated stack of pancakes after the flip
            flips++; // count the number of flips that have been made so far
        }
        cout << "solved in " << flips << " moves." << endl;

        cout << "0=quit, 1=new game, 2=old game: ";
        cin >> choice;
        if (choice == 2) 
        {
            printStack(pancakes);
            int flips = 0;
            while (!isSorted(pancakes)) 
            {
                cout << "flip point (1-" << numPancakes << ")? ";
                int index;
                cin >> index;
                flip(pancakes, index - 1);
                printStack(pancakes);
                flips++;
            }
            cout << "solved in " << flips << " moves." << endl;
        }
    }

    return 0;
}