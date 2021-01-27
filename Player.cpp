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
    }

    Player::~Player()
    {
        //dtor
    }

    void Player::getCard(bool show, Deck* deck)
    {
        this->hand.push_back(deck->getNextCard(show));           // add to current hand for this player
    }

    // display the players hand
    void Player::displayHand()
    {
        cout << this->getName() << " has ";
        bool firstCard = true;
        for(const auto& card : this->hand) {
            if (card->getShow() == true) {
                if (!firstCard) {
                    cout << " and ";
                }
                cout << " " << card->getName() << " of " << card->getSuit();
                this->totalValue += card->getValue();
                firstCard = false;
            }
        }
        cout << endl;
    }

    void Player::displayTotal() {
        cout << "The total for this hand is " << this->evaluateHand() << endl;
        cout << endl;
    }

    // show all the cards, turning over any cards face-down
    void Player::showAllCards() {
        for (const auto& card : this->hand) {
            if (card->getShow() == false) {
                card->setShow(true);
            }
        }
        this->displayHand();
    }

    // evaluate hand for Aces to determine if Ace is 1 or 11
    int Player::evaluateHand()
    {
        int totalValue = 0;
        for (const auto& card : this->hand) {
            totalValue += card->getValue();
            if (card->getName() == "Ace" && (totalValue + 10) <= 21) {
                totalValue += 10;
            }
        }
        this->setTotal(totalValue);

        return(totalValue);
    }

    void Player::clearHand() {
       for (const auto& card : this->hand) {
            this->hand.pop_back();
        }
    }
}
