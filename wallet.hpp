// wallet.hpp
// Andrew Adler and Adrian Antonio
// 12/01/17
// This is the header file for the Wallet class, with function and variable names

#ifndef FILE_WALLET_HPP_INCLUDED
#define FILE_WALLET_HPP_INCLUDED

class Wallet {
public:
    static bool setBet();   // Allows the player to place their wager in blackjack
    static void win(double payout); // How much the player wins at the end of a game
    
    static void slotsPay(); // Subtracts 1 unit from the player's wallet to play a round of slots
    static void slotsWin(int winValue); // What happens when a player gets a match in slots
    
    static void showWallet(); // Displays the player's current amount of money
	static int getWallet(); // Returns the player's current amount of money as a value
private:
    static int _currentMoney;
    static int _wager;
};

#endif // #ifndef FILE_WALLET_HPP_INCLUDED
