// blackjack.cpp

#include "cardgames.hpp"
#include "deck.hpp"

//ask the user if they want another card
bool player1() {
	cout << "Hit or Stay? ";
	string playerChoice;
	getline(cin, playerChoice);
	if (playerChoice == "hit") {
		return true;
	}
	return false;
}

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
    for (int i = 0; i < numAces; i++) {
        if (playerTotal > 21) {
            playerTotal -= 10;
        }
    }
    return playerTotal;
}

void showCards(vector<string> hand) {
	cout << "Cards dealt: ";
    for (auto i : hand) {
        if (i != hand[0]) {
            cout << ", ";
        }
        cout << i;
    }
    cout << endl << "Your total is: " << cardTotal(hand) << endl;
}

void blackjack() {
    while (true) {
        cout << "Starting a game of blackjack..." << endl << endl;
        vector<string> cards = Deck::getDeck();
        cout << "Dealing cards..." << endl << endl;
        vector<string> playerCards = Deck::deal(2, cards);
        showCards(playerCards);
        
        //gives a card

        while (cardTotal(playerCards) < 21) {
            if (player1()) {
                playerCards.push_back(Deck::plusOneCard(cards));
            }
            else {
                showCards(playerCards);
                break;
            }
            showCards(playerCards);
        }
        if (cardTotal(playerCards) < 21) {
            cout << "you might have won" << endl;
        }
        else if (cardTotal(playerCards) == 21) {
            cout << "you got a blackajck babyyyeuejjj" << endl;
        }
        else {
            cout << "You busted ya idiot! haha xD git gud scrub nub ggnore" << endl;
        }
    }
}
