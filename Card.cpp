#include<iostream>

#include "Card.h"

using namespace std;

namespace BlackJack {

    Card::Card() {
        // blank constructor
    }

    Card::Card(string name, string suit, int value, bool show)
    {
        this->setCard(name, suit, value, show);
    }

    Card::~Card()
    {
        //dtor
    }

    void Card::displayCard()
    {
        if (this->getShow() == true) {
            cout << this->getName() + " of " + this->getSuit();
        }
        else {
            cout << " (card face down) ";
        }
    }

    void Card::setCard(string name, string suit, int value, bool show)
    {
        this->setName(name);
        this->setSuit(suit);
        this->setValue(value);
        this->setShow(show);
    }
}
