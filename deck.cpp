// deck.cpp
// Andrew Adler and Adrian Antonio
// 12/01/17
// This is the source code for the Deck class, which is used with games that require a deck

#include "deck.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

// The deck base that is copied to games that use a deck of cards
vector<string> Deck::deckBase = {
    "A♠", "A♥", "A♣", "A♦",
    "2♠", "2♥", "2♣", "2♦",
    "3♠", "3♥", "3♣", "3♦",
    "4♠", "4♥", "4♣", "4♦",
    "5♠", "5♥", "5♣", "5♦",
    "6♠", "6♥", "6♣", "6♦",
    "7♠", "7♥", "7♣", "7♦",
    "8♠", "8♥", "8♣", "8♦",
    "9♠", "9♥", "9♣", "9♦",
    "10♠", "10♥", "10♣", "10♦",
    "J♠", "J♥", "J♣", "J♦",
    "Q♠", "Q♥", "Q♣", "Q♦",
    "K♠", "K♥", "K♣", "K♦"};

// Function used to copy the deck base
vector<string> Deck::getDeck() {
    return deckBase;
}

// Deals cards to the player and dealer initially
vector<string> Deck::deal(int numCards, vector<string> &dealFrom) {
    vector<string> dealtCards;
    for (int i = 0; i < numCards; i++) {
        random_device rd;
        mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib1(0,dealFrom.size()-1);
        int cardSpot = distrib1(gen);
        dealtCards.push_back(dealFrom[cardSpot]);
        dealFrom.erase(dealFrom.begin() + cardSpot);
    }
    return dealtCards;
}

// Adding one card to the player or dealer's hands
string Deck::plusOneCard(vector<string> &dealFrom) {
    vector<string> dealtCards;
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib1(0,dealFrom.size()-1);
    int cardSpot = distrib1(gen);
    return dealFrom[cardSpot];
}
