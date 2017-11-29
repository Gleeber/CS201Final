// Wallet.cpp
// Andrew Adler and Adrian Antonio
// 11/29/17
// This program manages the currency for the player

#include "wallet.hpp"
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
    cout << "Enter how much you want to bet: ";
    string input;
    getline(cin,input);
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

void Wallet::win() {
    Wallet::_currentMoney += Wallet::_wager * 2;
}

void Wallet::showWallet() {
    cout << "Your current balance is: " << Wallet::_currentMoney << endl;
}
