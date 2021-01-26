#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>

#include "card.h"
#include "deck.h"

using namespace std;

namespace BlackJack {

    class Player
    {
    public:
        Player(bool isDealer, string name);
        virtual ~Player();
        void displayHand();
        void getCard(bool show, Deck *deck);
        bool isBust();
        int evaluateHand();

        void setName(string name) { this->name = name; }
        string getName() { return this->name; }
        int getTotal() { return this->totalValue; }

    private:
        string name;
        bool isDealer;
        int numCardsInHand;
        std::list<Card*> hand;
//        Card* hand[10];
//        int handDex;        // index into hand
        int totalValue;
        int points;
    };
}
#endif // PLAYER_H
