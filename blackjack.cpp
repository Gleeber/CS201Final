// blackjack.cpp

#include "cardgames.hpp"
#include "deck.hpp"

//ask the user if they want another card
bool player1() {
	cout << "Hit or Stay?" << endl;
	string playerChoice;
	getline(cin, playerChoice);
	if (playerChoice == "hit") {
		return true;
	}
	return false;
}

void showCards(vector<string> & cards) {
	cout << "Cards dealt: ";
	for (auto i : cards) {
		cout << i << ", ";
	}
	cout << endl;
}

void blackjack() {
    cout << "Running blackjack:" << endl;
    vector<string> cards = Deck::getDeck();
    cout << "Dealing cards..." << endl;
    vector<string> playerCards = Deck::deal(2, cards);
	showCards(playerCards);
	

	//gives a card

	while (true) {

		if (player1()) {
			vector<string> plusOneCard = Deck::deal(1, cards);
			for (auto i : plusOneCard) {
				playerCards.push_back(i);
			}
			showCards(playerCards);
			cout << endl;
		}
		else {
			break;
		}
	}
}
