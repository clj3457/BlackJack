#include <iostream>
#include <list>

#include "player.h"

using namespace std;

namespace BlackJack {

    Player::Player(bool isDealer, string name)
    {
        this->isDealer = isDealer;
        this->numCardsInHand = 0;
        this->totalValue = 0;
        this->name = name;
        this->points = 0;
//        this->handDex = 0;
    }

    Player::~Player()
    {
        //dtor
    }

    void Player::getCard(bool show, Deck* deck)
    {
        //if ((this->handDex + 1) == 10) {
        //    cout << "\nHand is full, no more cards allowed!";
        //    return;
        //}
//        this->hand[this->handDex] = deck->getNextCard(show);
//        this->handDex++;
        this->hand.push_back(deck->getNextCard(show));           // add to current hand for this player
    }

    void Player::displayHand()
    {
        cout << this->getName() << " has ";
//        list<Card*>::iterator cardIdx;
//        for (cardIdx = this->hand.begin(); cardIdx != hand.end(); cardIdx++) {
        bool firstCard = true;
        for(const auto& card : this->hand) {
            if (!firstCard) {
                cout << " and ";
            }
            cout << " " << card->getName() << " of " << card->getSuit();
            this->totalValue += card->getValue();
            firstCard = false;
        }
        cout << endl;
        cout << "The total for this hand is " << this->getTotal() << endl;
    }

    // evaluate hand for Aces to determine if Ace is 1 or 11
    int Player::evaluateHand()
    {
//        list<Card>::iterator cardIdx;
//        for (cardIdx = this->hand.begin(); cardIdx != hand.end(); cardIdx++) {
        for (const auto& card : this->hand) {
            if (card->getName() == "Ace" && (this->totalValue + 10) <= 21) {
                this->totalValue += 10;
                break;
            }
        }
        return(this->totalValue);
    }

    bool Player::isBust()
    {
        if (this->totalValue > 21) {
            cout << "\nPlayer " + this->getName() + " is BUST! Game Over!";
                return true;
        }
        else {
            return false;
        }
    }
}
