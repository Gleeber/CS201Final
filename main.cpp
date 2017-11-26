// main.cpp

#include "cardgames.hpp"

int main() {
    cout << "What game do you want to play?: ";
    string input;
    getline(cin, input);
    if (input == "blackjack") {
        blackjack();
    }
    return 0;
}
