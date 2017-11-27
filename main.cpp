// main.cpp

#include "cardgames.hpp"

int main() {
    cout << "Possible games: " << endl << "   blackjack" << endl;
    cout << "Enter the game you want to play: ";
    string input;
    getline(cin, input);
    if (input == "blackjack") {
        blackjack();
    }
    
    cout << "Press ENTER to quit ";
    while (cin.get() != '\n') ;
    return 0;
}
