// blackjack.cpp

#include "cardgames.hpp"
#include "deck.hpp"

void blackjack() {
    cout << "Running blackjack:" << endl;
    vector<string> cards = Deck::getDeck();
    cout << "Dealing cards..." << endl;
    vector<string> playerCards = Deck::deal(2, cards);
    cout << "Cards dealt: ";
    for (auto i : playerCards) {
        cout << i << ", ";
    }
}
