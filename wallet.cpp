// wallet.cpp
// Andrew Adler and Adrian Antonio
// 12/01/17
// This is the source code for the Wallet class, which manages the player's bank

#include "wallet.hpp"
#include "cardgames.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;

int Wallet::_currentMoney = 500;
int Wallet::_wager = 0;

bool Wallet::setBet() {
    cout << "You currently have " << Wallet::getWallet() << " in your bank" << endl;
    cout << "Enter how much you want to bet: ";
    string input;
    getline(cin,input);
    cout << endl;
    if(!cin) {
        cout << "Error in input. Try again." << endl;
        return false;
    }
    
    int wager;
    istringstream iss(input);
    iss >> wager;
    if (!iss) {
        cout << "Wager must be a number." << endl;
        return false;
    }
    
    if (wager < 1) {
        cout << "You must place a wager greater than 0." << endl;
        return false;
    }
    
    if (Wallet::_currentMoney < wager) {
        cout << "You have insufficient funds to place that bet." << endl;
        return false;
    }
    
    Wallet::_currentMoney -= wager;
    Wallet::_wager = wager;
    cout << "Wager of " << wager << " has been placed." << endl;
    return true;
}

void Wallet::win(double payout) {
    Wallet::_currentMoney += Wallet::_wager * payout;
}

void Wallet::slotsPay() {
    Wallet::_currentMoney--;
}

void Wallet::slotsWin(int winValue) {
    switch (winValue) {
        case 0:
            cout << "You won 5 units!";
            Wallet::_currentMoney += 5;
            break;
        case 1:
            cout << "Pulling again for free..." << endl << endl;
            slots(true);
            break;
        case 2:
            cout << "You won 50 units!";
            Wallet::_currentMoney += 50;
            break;
        case 3:
            cout << "You won 100 units!";
            Wallet::_currentMoney += 100;
            break;
        case 4:
            cout << "You hit the Jackpot!" << endl;
            cout << "You won 1000 units!";
            Wallet::_currentMoney += 1000;
            break;
            
        default:
            break;
    }
}

void Wallet::showWallet() {
    cout << endl << "Your current balance is: " << Wallet::_currentMoney << endl << endl;
}

int Wallet::getWallet() {
	return Wallet::_currentMoney;
}
