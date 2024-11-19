#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>   
#include <cstring> 

using namespace std;

// Function to roll a single die with d sides
char roll_die(int d)
{
    return rand() % d + 1;
}

// Overloaded function to roll a single 6-sided die
char roll_die()
{
    return roll_die(6);
}

// Function to compute the sum of n rolls of d-sided dice
int roll_dice_sum(int d, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += roll_die(d);
    }
    return sum;
}

// Overloaded function to compute the sum of 5 rolls of 6-sided dice
int roll_dice_sum()
{
    return roll_dice_sum(6, 5);
}

// Function to fill a vector with the counts of possible outcomes for r rolls of d-sided dice
void fill_counts(vector<int>& counts, int d, int n, int r)
{
    // Reset the counts to zero
    counts.assign(d * n + 1, 0);

    // Roll the dice r times and count the outcomes
    for (int i = 0; i < r; i++)
    {
        int sum = roll_dice_sum(d, n);
        counts[sum]++;
    }
}

// Overloaded function to fill a vector with the counts of possible outcomes for 1000 rolls of 6-sided dice
void fill_counts(vector<int>& counts)
{
    fill_counts(counts, 6, 5, 1000);
}

// Function to display a histogram of the counts using ASCII characters
void display_histogram(const vector<int>& counts)
{
    const int MAX_HISTOGRAM_HEIGHT = 20;
    int max_count = 0;
    for (int count : counts)
    {
        max_count = max(max_count, count);
    }
    double scale = (max_count > MAX_HISTOGRAM_HEIGHT) ? (double)MAX_HISTOGRAM_HEIGHT / max_count : 1.0;

    for (int i = 0; i < counts.size(); i++)
    {
        cout << i << ": ";
        int height = counts[i] * scale;
        for (int j = 0; j < height; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Generalized program for d-sided dice, n in sum, and r rolls
    int d, n, r;
    cout << "Enter the number of sides on the dice: ";
    cin >> d;
    cout << "Enter the number of dice to roll for each sum: ";
    cin >> n;
    cout << "Enter the number of rolls to simulate: ";
    cin >> r;

    vector<int> counts;
    fill_counts(counts, d, n, r);
    display_histogram(counts);

    return 0;
}
