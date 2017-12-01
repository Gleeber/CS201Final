// main.cpp

#include "cardgames.hpp"
#include "wallet.hpp"

int main() {
	while (Wallet::getWallet() > 0) {
		cout << "Possible games: " << endl << "   blackjack" << endl;
		cout << "Enter the game you want to play: ";
		string input;
		getline(cin, input);
		if (input == "blackjack") {
			blackjack();
		}
	}
	cout << "You lack the necessary funds \n to continue from playing." << endl;
	cout << "Press ENTER to quit ";
	while (cin.get() != '\n');
	return 0;
}
