// main.cpp
// Andrew Adler and Adrian Antonio
// 12/01/17
// This is the "casino lobby" where the player can decide what game to play

#include "cardgames.hpp"
#include "wallet.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;

// Function used for getting string inputs that are not case sensitive
bool getInput(string &inputVariable) { // Output is a bool to make sure cin worked properly
    getline(cin, inputVariable);
    cout << endl;
    if (!cin) {
        cout << "Error in input. Run the program again." << endl;
        return false;
    }
    for (auto i = 0; i < inputVariable.size(); i++) {
        inputVariable[i] = tolower(inputVariable[i]);
    }
    return true;
}

int main() {
	while (Wallet::getWallet() > 0) {
        bool continueGame = true;
        cout << "Possible games: " << endl
            << "   blackjack" << endl
            << "   slots" << endl
            << "   leave (if you want to quit)" << endl;
		cout << "Enter the game you want to play: ";
        string input;
        if(!getInput(input)) return 1;
        
        if (input == "leave") {
            cout << "Leaving the casino." << endl;
            break;
        }
        
        if (input != "blackjack" && input != "slots") {
            cout << "Please enter a valid game." << endl;
            continue;
        }
        
        while (continueGame) { // Allows the player to quickly play the same game multiple times
            if (input == "blackjack") {
                blackjack();
            }
            if (input == "slots") {
                slots(false);
            }
            if (Wallet::getWallet() < 1) {
                break;
            }
            
            cout << "Do you want to continue playing " << input << "?" << endl << "Enter \"yes\" or \"no\": ";
            string continuePlaying;
            while(true) {
                if(!getInput(continuePlaying)) return 1;
                if (continuePlaying == "no") {
                    continueGame = false;
                }
                else if (continuePlaying != "yes") {
                    cout << "Enter \"yes\" or \"no\": ";
                    continue;
                }
                break;
            }
        }
	}
    // Leaving the casino lobby
    
    // If the player is leaving the casino because they have no money left
    if (Wallet::getWallet() < 1) {
        cout << "You ran out of money..." << endl << "Leaving the casino." << endl << endl;
    }
//	cout << "Press ENTER to quit ";
//	while (cin.get() != '\n');
//	return 0;
}
