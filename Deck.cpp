
#include <vector>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>  
#include <iostream>

#include "Card.h"
#include "Deck.h"

using namespace std;

namespace BlackJack {

    Deck::Deck(int num) {
        this->numDecks = num;
        this->numCardsInDeck = MAX_CARDS * this->numDecks;     // set total number of cards in deck
        this->deckIndex = 0;
        initializeDeck();
    }

    Deck::~Deck() {
        // ---
    }

    // constructor to set up the deck
    void Deck::initializeDeck()
    {
        // set up blank deck
        cardDeck.resize(this->numCardsInDeck);

        // set up each card in deck
        this->deckIndex = 0;
        for (int deck = 0; deck < this->numDecks; deck++) {
            for (int suit = 0; suit < MAX_SUITS; suit++) {
                for (int crd = 0; crd < CARDS_PER_SUIT; crd++) {
                    cardDeck[this->deckIndex].setCard(names[crd], suitTypes[suit], values[crd], false);
                    this->deckIndex++;
                }
            }
        }
        // shuffle the deck
        shuffleDeck();
    }

    // shuffle the deck
    void Deck::shuffleDeck() {
        // shuffle the deck
        random_shuffle(cardDeck.begin(), cardDeck.end());
    }

    // get pointer to next card in deck
    Card* Deck::getNextCard(bool show)
    {
        if (this->deckIndex > 0) {
            this->deckIndex--;
        }
        else {
            cout << "\nNo more cards in the deck.";
            return NULL;
        }
        this->cardDeck[this->deckIndex].setShow(show);
        return(&this->cardDeck[this->deckIndex]);
    }
}