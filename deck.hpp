//
//  deck.hpp
//  CS201FinalLocal
//
//  Created by Andrew Adler on 11/27/17.
//  Copyright © 2017 Andrew Adler. All rights reserved.
//

#ifndef FILE_DECK_HPP_INCLUDED
#define FILE_DECK_HPP_INCLUDED

#include <string>
using std::string;
#include <vector>
using std::vector;

class Deck {
public:
    static vector<string> deal(int numCards, vector<string> &dealFrom);
    static string plusOneCard(vector<string> &dealFrom);
    static vector<string> getDeck();
private:
    static vector<string> deckBase;
};

#endif // #ifndef FILE_DECK_HPP_INCLUDED
