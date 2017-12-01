// slots.cpp
// Andrew Adler and Adrian Antonio
// 12/01/17
// This is the source code for everything involved with blackjack

#include "cardgames.hpp"
#include "wallet.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;


// The possible winning conditions for slots
void slotPayouts() {
    cout << "Payouts:" << endl;
    cout << "   Matching three 🍒's:        5 units" << endl;
    cout << "   Matching three \"Replays\":   Free spin" << endl;
    cout << "   Matching three ★'s:         50 units" << endl;
    cout << "   Matching three 💎's:        100 units" << endl;
    cout << "   Matching three 7's:         1000 units" << endl;
}

// The main slots function
void slots(bool free) { // "free" is true when a game is played by matching three Replays
    while(true) {
        cout << "Press ENTER to pull, type \"about\" for payouts, or type \"leave\" to leave: ";
        string slotsAction;
        getInput(slotsAction);
        
        if (slotsAction == "leave") {
            cout << "Leaving slots." << endl;
            break;
        }
        
        else if (slotsAction == "about") {
            slotPayouts();
            continue;
        }
        
        // When the player pulls the slot machine
        else {
            if (!free) { // Doesn't require payment for matching three Replays
                cout << "Starting a game of slots..." << endl << endl;
                Wallet::slotsPay();
            }
            vector<string> slotWheel { "🍒", "Replay", "★", "💎", "7" };
            int slotSpot = 0;
            vector<string> slotResults;
            
            // Randomizing each of the 3 slot machine lanes
            for (int i = 0; i < 3; i++) {
                random_device rd;
                mt19937 gen(rd());
                std::uniform_int_distribution<int> distrib1(1,100);
                int randNum = distrib1(gen);
                
                // The possibilities for stopping on each of the slot values
                if (randNum <= 35) {
                    slotSpot = 0;
                }
                else if (randNum <= 60) {
                    slotSpot = 1;
                }
                else if (randNum <= 80) {
                    slotSpot = 2;
                }
                else if (randNum <= 95) {
                    slotSpot = 3;
                }
                else if (randNum <= 100) {
                    slotSpot = 4;
                }
                slotResults.push_back(slotWheel[slotSpot]);
            }
            
            cout << "Results: ";
            for (int i = 0; i < 3; i++) {
                if (i != 0) {
                    cout << " | ";
                }
                cout << slotResults[i];
            }
            cout << endl;
            
            // When a match occurs
            if (slotResults[0] == slotResults[1] && slotResults[0] == slotResults[2]) {
                Wallet::slotsWin(slotSpot);
            }
            if (!free) {
                Wallet::showWallet();
            }
        }
        
        if (free) { // So that it only runs once when the player matches three Replays
            break;
        }
    }
}
