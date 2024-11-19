#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

double getPayoff(int dog, double bet, double probs[]) {
    double prob = probs[dog];
    double fee = 1.0;
    return bet / prob - fee;
}

int main() {
    double account = 100.0;
    double probs[] = {0.4, 0.1, 0.2, 0.2, 0.1};
    srand(time(NULL));
    int numRaces = 5;
    for (int race = 1; race <= numRaces; race++) {
        cout << "Here are the dogs you can bet on:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "dog " << i << " prob:" << fixed << setprecision(0) << probs[i] * 100 << "%" << endl;
        }
        cout << "You have $" << fixed << setprecision(2) << account << " available." << endl;
        int dog = -1;
        while (dog < 0 || dog >= 5) {
            cout << "Pick a dog: ";
            cin >> dog;
        }
        if (dog < 0 || dog >= 5) {
            cout << "Invalid dog number." << endl;
            continue;
        }
        double bet = -1.0;
        while (bet < 0.0 || bet > account) {
            cout << "Enter dollars to bet (0 to quit): ";
            cin >> bet;
        }
        if (bet == 0.0) {
            break;
        }
        double payoff = getPayoff(dog, bet, probs);
        cout << "You bet $" << fixed << setprecision(2) << bet << " on dog " << dog << "." << endl;
        double winProb = (double) rand() / RAND_MAX;
        if (winProb <= probs[dog]) {
            cout << "Your dog won!!" << endl;
            account += payoff;
        } else {
            cout << "You dog lost and you now have $" << fixed << setprecision(2) << (account - bet) << " in your account." << endl;
            account -= bet;
        }
    }
    cout << "Bye" << endl;
    return 0;
}
