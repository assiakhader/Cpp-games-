#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

int calculateHandValue(const std::vector<int>& hand) {
    int total = 0;
    int aceCount = 0;

    for (int card : hand) {
        if (card == 1) { // Ace
            aceCount++;
            total += 11;
        } else if (card > 10) { // Face cards (Jack, Queen, King)
            total += 10;
        } else {
            total += card;
        }
    }

    // Adjust for Aces if the total is over 21
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }

    return total;
}

int drawCard() {
    return std::rand() % 13 + 1;
}

void displayHand(const std::vector<int>& hand, const std::string& owner) {
    std::cout << owner << "'s hand: ";
    for (int card : hand) {
        if (card == 1) {
            std::cout << "[A] ";
        } else if (card == 11) {
            std::cout << "[J] ";
        } else if (card == 12) {
            std::cout << "[Q] ";
        } else if (card == 13) {
            std::cout << "[K] ";
        } else {
            std::cout << "[" << card << "] ";
        }
    }
    std::cout << "(Total: " << calculateHandValue(hand) << ")\n";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "=========================================\n";
    std::cout << "           Welcome to Blackjack!         \n";
    std::cout << "=========================================\n";

    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);

    int balance = 100; // Starting money for the player
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        // Display balance
        std::cout << "\n=========================================\n";
        std::cout << "Your current balance: $" << balance << "\n";
        std::cout << "=========================================\n";

        // Get the player's bet
        int bet;
        std::cout << "Enter your bet amount: $";
        std::cin >> bet;

        // Validate the bet
        while (bet <= 0 || bet > balance + 100) { // Allow going into debt up to $100
            std::cout << "Invalid bet! You can bet up to $" << balance + 100 << ".\n";
            std::cout << "Enter a valid bet amount: $";
            std::cin >> bet;
        }

        // Initialize hands
        std::vector<int> playerHand;
        std::vector<int> dealerHand;

        // Deal initial cards
        playerHand.push_back(drawCard());
        playerHand.push_back(drawCard());
        dealerHand.push_back(drawCard());
        dealerHand.push_back(drawCard());

        // Display initial hands
        std::cout << "\n=========================================\n";
        std::cout << "            Initial Hands                \n";
        std::cout << "=========================================\n";
        displayHand(playerHand, "Player");
        std::cout << "Dealer's revealed card: ";
        if (dealerHand[0] == 1) {
            std::cout << "[A]";
        } else if (dealerHand[0] > 10) {
            std::cout << "[" << (dealerHand[0] == 11 ? "J" : dealerHand[0] == 12 ? "Q" : "K") << "]";
        } else {
            std::cout << "[" << dealerHand[0] << "]";
        }
        std::cout << "\n";

        // Player's turn
        bool playerBust = false;
        while (true) {
            char choice;
            std::cout << "\nDo you want to (H)it or (S)tand? ";
            std::cin >> choice;

            if (choice == 'H' || choice == 'h') {
                playerHand.push_back(drawCard());
                displayHand(playerHand, "Player");
                if (calculateHandValue(playerHand) > 21) {
                    std::cout << "You bust! Your total exceeds 21.\n";
                    playerBust = true;
                    break;
                }
            } else if (choice == 'S' || choice == 's') {
                break;
            } else {
                std::cout << "Invalid choice. Please enter 'H' or 'S'.\n";
            }
        }

        // Dealer's turn
        bool dealerBust = false;
        if (!playerBust) {
            std::cout << "\n=========================================\n";
            std::cout << "              Dealer's Turn              \n";
            std::cout << "=========================================\n";
            displayHand(dealerHand, "Dealer");

            while (calculateHandValue(dealerHand) < 17) {
                std::cout << "Dealer hits.\n";
                dealerHand.push_back(drawCard());
                displayHand(dealerHand, "Dealer");
            }

            if (calculateHandValue(dealerHand) > 21) {
                std::cout << "Dealer busts! You win this round.\n";
                dealerBust = true;
            }
        }

        // Determine the result
        std::cout << "\n=========================================\n";
        std::cout << "              Final Results              \n";
        std::cout << "=========================================\n";
        displayHand(playerHand, "Player");
        displayHand(dealerHand, "Dealer");

        if (playerBust) {
            std::cout << "You lose this round.\n";
            balance -= bet;
        } else if (dealerBust) {
            std::cout << "You win this round!\n";
            balance += bet;
        } else {
            int playerTotal = calculateHandValue(playerHand);
            int dealerTotal = calculateHandValue(dealerHand);

            if (playerTotal > dealerTotal) {
                std::cout << "You win this round!\n";
                balance += bet;
            } else if (playerTotal < dealerTotal) {
                std::cout << "You lose this round.\n";
                balance -= bet;
            } else {
                std::cout << "It's a tie! No money won or lost.\n";
            }
        }

        std::cout << "\nYour current balance: $" << balance << "\n";
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            std::cout << "\nThank you for playing, " << playerName << "! Your final balance is $" << balance << ".\n";
        }
    }

    return 0;
}
