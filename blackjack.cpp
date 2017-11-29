// blackjack.cpp

#include "cardgames.hpp"
#include "deck.hpp"
#include "wallet.hpp"

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
    cout << endl << "Total is: " << cardTotal(hand) << endl;
}
bool dealerLogic(vector<string> hands,vector<string> deck) {
	while (cardTotal(hands) < 17) {
		hands.push_back(Deck::plusOneCard(deck));	
	}
	showCards(hands);
	if (cardTotal(hands) > 21) {
		cout << "DEALR BUST! YOU WIN!" << endl;
        Wallet::win();
		return false;
	}
	return true;
}

void blackjack() {
    while (true) {
        cout << "Starting a game of blackjack..." << endl << endl;
        while(!Wallet::setBet());
        vector<string> cards = Deck::getDeck();
        cout << "Dealing cards..." << endl << endl;
		vector<string> playerCards = Deck::deal(2, cards);//player gets his card
		showCards(playerCards);
		vector<string> dealerCards = Deck::deal(2, cards);//dealer gets his card
		cout << endl << "Dealer's Hand: " << dealerCards[0] << endl;


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
			cout << endl;
			cout << "Dealer's" << endl;
			if (dealerLogic(dealerCards, cards)) {

				if (cardTotal(playerCards) > cardTotal(dealerCards)) {
					cout << "You have won against the Dealer." << endl;
                    Wallet::win();
				}
				else {
					cout << "You have lost against the Dealer." << endl;
				}
			}
		}
		
        else if (cardTotal(playerCards) == 21) {
            cout << "you got a blackajck babyyyyy :DDDDD" << endl;
            Wallet::win();
        }
        else {
            cout << "You busted ya idiot! haha xD git gud scrub nub ggnore" << endl;
        }
        Wallet::showWallet();
    }
}
