#pragma once
//#ifndef CARD_H
//#define CARD_H

#include <string>

using namespace std;

namespace BlackJack {

    class Card
    {
    public:
        Card();
        Card(string name, string suit, int value, bool show);
        virtual ~Card();

        string getName() { return name; }
        void setName(string val) { name = val; }
        string getSuit() { return suit; }
        void setSuit(string val) { suit = val; }
        int getValue() { return value; }
        void setValue(int val) { value = val; }
        bool getShow() { return show; }
        void setShow(bool value) { show = value; }

        void displayCard();
        void setCard(string name, string suit, int value, bool show);

    protected:

    private:
        string name = "";
        string suit = "";
        int value = 0;
        bool show = false;
    };
}

//#endif      // CARD_H
