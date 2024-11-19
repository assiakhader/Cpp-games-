#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function to load the data from a file into two vectors: questions and answers
void loadDataFromFile(string filename, vector<string>& players, vector<string>& teams) 
{
    // Open the file with the given name
    ifstream inFile(filename);

    // Check if the file is successfully opened
    if (inFile.is_open()) 
    {
        // Read the first line of the file and discard it (assuming it's a header line)
        string header;
        getline(inFile, header);

        // Read all the next lines and split them into a player and team
        string player, team;
        while (getline(inFile, player, ',') && getline(inFile, team)) 
        {
            // Add the player and team to their respective vectors
            players.push_back(player);
            teams.push_back(team);
        }

        // Close the file
        inFile.close();
    } 
    else 
    {
        // Print an error message if the file couldn't be opened
        cout << "Error opening file: " << filename << endl;
    }
}

int main() 
{
    // Instructions for the user
    cout << "Welcome to the Player-Teams Data Program!" << endl;
    cout << "This program reads a file containing players and teams, and then displays lists of players and teams." << endl;
    cout << "\nInstructions for the file format:" << endl;
    cout << "Prepare a .txt file with each line containing a player and their associated team." << endl;
    cout << "The format should be: 'player_name,team_name' on each line." << endl;
    cout << "Example file content:\n";
    cout << "   Messi,Barcelona\n";
    cout << "   Ronaldo,Juventus\n";
    cout << "   Neymar,PSG\n";
    cout << "After running the program, it will output two lists: one for players and one for teams." << endl;

    // Prompt the user to enter the filename containing the data
    string filename;
    cout << "\nEnter filename (e.g., sports.txt): ";
    getline(cin, filename);

    // Vectors to store players and teams data
    vector<string> players, teams;

    // Load the data from the file into vectors
    loadDataFromFile(filename, players, teams);

    // Output the list of players
    cout << "\nList of players:" << endl;
    for (const auto& player : players) {
        cout << player << endl;
    }

    // Output the list of teams
    cout << "\nList of teams:" << endl;
    for (const auto& team : teams) {
        cout << team << endl;
    }

    return 0;
}
