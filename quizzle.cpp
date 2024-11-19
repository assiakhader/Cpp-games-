// Assia KHADER
// ITP 165, 2023 Spring
// Quizzle 

#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

// Function to load the data from a file into two vectors: questions and answers
void loadDataFromFile(string filename, vector<string>& questions, vector<string>& answers) 
{
    // Open the file with the given name
    ifstream inFile(filename);

    // Check if the file is successfully opened
    if (inFile.is_open()) 
    {
        // Read the first line of the file and discard it (assuming it's a header line)
        string header;
        getline(inFile, header);

        // Read all the next lines and split them into a question and an answer
        string question, answer;
        while (getline(inFile, question, ',') && getline(inFile, answer)) 
        {
            // Add the question and answer to their respective vectors
            questions.push_back(question);
            answers.push_back(answer);
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

// Function to pick 5 random question-answer pairs without repetition
vector<int> pickRandomQuestions(int numQuestions) 
{
    // Create a vector containing the indices of all the questions
    vector<int> indices(numQuestions);
    for (int i = 0; i < numQuestions; i++) 
    {
        indices[i] = i;  // Indices range from 0 to numQuestions - 1
    }

    // Shuffle the vector of indices by making random swaps
    for (int i = 0; i < numQuestions; i++) 
    {
        int j = rand() % numQuestions;
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    // Return the first 5 indices in the shuffled vector
    return vector<int>(indices.begin(), indices.begin() + 5);
}

// Function to ask one question and return true if the answer is correct
bool askQuestion(string question, string answer) 
{
    // Get the user's answer to the question
    string userAnswer;
    cout << question << " ? : ";
    getline(cin, userAnswer);

    // Compare the user's answer to the correct answer and print a message indicating whether the answer was correct
    bool correct = userAnswer == answer;
    if (correct) 
    {
        cout << "Correct!" << endl;
    } 
    else 
    {
        cout << "Oops, the correct answer is " << answer << "." << endl;
    }

    // Return true if the user's answer was correct, false otherwise
    return correct;
}

// Function to run the quiz on the 5 randomly selected questions
void runQuiz(vector<string>& questions, vector<string>& answers) 
{
    // Pick 5 random questions to ask in the quiz
    vector<int> indices = pickRandomQuestions(questions.size());

    // Initialize a counter for the number of correct answers
    int numCorrect = 0;

    // Ask each of the randomly selected questions and update the counter if the answer is correct
    for (int i = 0; i < indices.size(); i++) 
    {
        int index = indices[i];
        if (askQuestion(questions[index], answers[index])) 
        {
            numCorrect++;
        }
    }

    // Print the user's score at the end of the quiz
    cout << "You got " << numCorrect << " correct." << endl;
}

int main() 
{
    // Introduction message
    cout << "Welcome to Quizzle! This is a quiz program where you will answer random questions.\n";
    cout << "Instructions:\n";
    cout << "Prepare a CSV file containing the questions and answers.\n";
    cout << "The file should be formatted as follows:\n";
    cout << "   - Each line should contain a question and an answer, separated by a comma.\n";
    cout << "   - Example entry: 'What is the capital of France?,Paris'\n";
    cout << "The program will randomly pick 5 questions from the file and ask you to answer them.\n";
    cout << "After answering all the questions, the program will tell you how many you got correct:)\n\n";

    // Ask for the filename containing the quiz data
    string filename;
    cout << "Enter filename of quiz data (e.g., quiz_data.txt): ";
    getline(cin, filename);

    // Vectors to hold questions and answers from the file
    vector<string> questions, answers;

    // Load the data from the file into the vectors
    loadDataFromFile(filename, questions, answers);

    // Variable to control whether the user wants to repeat the quiz
    char repeat;

    do 
    {
        // Run the quiz using the loaded questions and answers
        runQuiz(questions, answers);

        // Ask the user if they want to take the quiz again
        cout << "Do you want to quiz again? (y/n): ";
        cin >> repeat;
        cin.ignore();  // Clear the newline character left in the input buffer
    } 
    while (repeat == 'y');

    // Goodbye message
    cout << "Thank you for using Quizzle! Goodbye!" << endl;

    return 0;
}
