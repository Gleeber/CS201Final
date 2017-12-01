// blackjack.cpp
// Andrew Adler and Adrian Antonio
// 12/01/17
// This is the source code for everything involved with blackjack

#include "cardgames.hpp"
#include "deck.hpp"
#include "wallet.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;

// Asks the user whether they want to hit or stay
bool playerChoice() {
    while (true) {
        cout << "Hit or Stay?: ";
        string playerChoice;
        getInput(playerChoice);
        if (playerChoice == "hit") {
            return true;
        }
        else if (playerChoice == "stay") {
            return false;
        }
        else {
            cout << "Please enter \"hit\" or \"stay\"" << endl;
            continue;
        }
    }
}

// Counts the total value of a player's hand
int cardTotal(vector<string> cardsToCount) {
    int playerTotal = 0;
    int numAces = 0;
    for (auto i : cardsToCount) {
        switch (i[0]) {
            case 'A':
                playerTotal += 11;
                numAces ++;
                break;
            case '2':
                playerTotal += 2;
                break;
            case '3':
                playerTotal += 3;
                break;
            case '4':
                playerTotal += 4;
                break;
            case '5':
                playerTotal += 5;
                break;
            case '6':
                playerTotal += 6;
                break;
            case '7':
                playerTotal += 7;
                break;
            case '8':
                playerTotal += 8;
                break;
            case '9':
                playerTotal += 9;
                break;
            case '1':
            case 'J':
            case 'Q':
            case 'K':
                playerTotal += 10;
                break;
            default:
                break;
        }
    }
    
    // Logic for if aces are in the hand
    for (int i = 0; i < numAces; i++) {
        if (playerTotal > 21) {
            playerTotal -= 10;
        }
    }
    return playerTotal;
}

// Displays a player's current hand
void showCards(vector<string> hand) {
	cout << "Cards dealt: ";
    for (auto i : hand) {
        if (i != hand[0]) {
            cout << ", ";
        }
        cout << i;
    }
    cout << endl << "Total is: " << cardTotal(hand) << endl;
}

// Forces the dealer to draw cards until their card total is 17 or more
bool dealerLogic(vector<string> &hands,vector<string> deck) {
	while (cardTotal(hands) < 17) {
		hands.push_back(Deck::plusOneCard(deck));	
	}
	showCards(hands);
	if (cardTotal(hands) > 21) {
		cout << "DEALER BUST! YOU WIN!" << endl;
        Wallet::win(2);
		return false;
	}
	return true;
}

// The blackjack game
void blackjack() {
    cout << "Starting a game of blackjack..." << endl << endl;
    while (!Wallet::setBet());
    vector<string> cards = Deck::getDeck();
    cout << "Dealing cards..." << endl << endl;
    vector<string> playerCards = Deck::deal(2, cards); //player gets their cards
    showCards(playerCards);
    vector<string> dealerCards = Deck::deal(2, cards); //dealer gets their cards
    cout << endl << "Dealer's revealed card: " << dealerCards[0] << endl;

    // Until player's total reaches 21, they can hit or stay
    while (cardTotal(playerCards) < 21) {
        if (playerChoice()) {
            playerCards.push_back(Deck::plusOneCard(cards));
        }
        else {
            showCards(playerCards);
            break;
        }
        showCards(playerCards);
    }
    
    // If the player stays, their card total is compared to the dealer's
    if (cardTotal(playerCards) < 21) {
        cout << endl;
        cout << "Dealer's hand" << endl;
        if (dealerLogic(dealerCards, cards)) {
            if (cardTotal(playerCards) > cardTotal(dealerCards)) {
                cout << "You beat the dealer!" << endl;
                Wallet::win(2);
            }
            else if (cardTotal(dealerCards) == cardTotal(playerCards)) {
                cout << "It's a tie!" << endl;
                Wallet::win(1);
            }
            else {
                cout << "You have lost against the dealer..." << endl;
            }
        }
    }

    // If the player gets a blackjack, they win more
    else if (cardTotal(playerCards) == 21) {
        cout << "You got a blackajck!" << endl;
        cout << "Returning triple your wager back..." << endl;
        Wallet::win(3);
    }
    
    // If the player busts, they lose
    else {
        cout << "You busted! You lose!" << endl;
    }
    Wallet::showWallet();
}

