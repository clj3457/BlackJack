#pragma once
//#ifndef DECK_H
//#define DECK_H

#include <string>
#include <vector>

#include "Card.h"

using namespace std;
using namespace BlackJack;

namespace BlackJack {

    class Deck
    {
    public:
        const int MAX_CARDS = 52;
        const int MAX_SUITS = 4;
        const int CARDS_PER_SUIT = 13;

        Deck(int num);
        virtual ~Deck();

        void setNumDecks(int num) { this->numDecks = num; }
        Card* getNextCard(bool show);
        void initializeDeck();
        void shuffleDeck();

    private:
        const string names[13] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
        const int values[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
        const string suitTypes[4] = { "Spades", "Clubs", "Hearts", "Diamonds" };

        int numDecks;
        int numCardsInDeck;

        vector<Card> cardDeck;

        int deckIndex;
    };
}

//#endif // DECK_H
