// deck.hpp
// Andrew Adler and Adrian Antonio
// 12/01/17
// This is the header file for the Deck class

#ifndef FILE_DECK_HPP_INCLUDED
#define FILE_DECK_HPP_INCLUDED

#include <string>
using std::string;
#include <vector>
using std::vector;

class Deck {
public:
    static vector<string> getDeck(); // Makes a copy of the deck
    
    static vector<string> deal(int numCards, vector<string> &dealFrom); // Deals a hand
    static string plusOneCard(vector<string> &dealFrom); // Adds one card to the hand
private:
    static vector<string> deckBase; // The deck base that is copied to games that use a deck of cards
};

#endif // #ifndef FILE_DECK_HPP_INCLUDED
