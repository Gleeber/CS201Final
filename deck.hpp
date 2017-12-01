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
    static vector<string> getDeck();
    
    static vector<string> deal(int numCards, vector<string> &dealFrom);
    static string plusOneCard(vector<string> &dealFrom);
private:
    static vector<string> deckBase;
};

#endif // #ifndef FILE_DECK_HPP_INCLUDED
