// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;
using namespace BlackJack;


    int main()
    {
        Deck deck(1);                                   // set up one deck
        Player dealer(true, "Dealer");   // set the dealer
        Player player1(false, "Player 1"); // set up player1
        bool gameOn = true;
        char playerInput;

        // deal 2 cards to dealer with 1 face up and 1 face down
        dealer.getCard(false, &deck);        // 1st dealer card face down, the rest are face up
        dealer.getCard(true, &deck);
        dealer.displayHand();

        // deal 2 cards face up to player
        player1.getCard(false, &deck);
        player1.getCard(false, &deck);
        player1.displayHand();

        // play game until 21 reached or a player goes bust or all players are done
        while (gameOn) {
                // check if dealer needs another card
            if (dealer.getTotal() < 17) {
                dealer.getCard(true, &deck);
            }
            if(dealer.getTotal() == 21) {
                cout << "Dealer hit 21! House wins!" << endl;
                gameOn = false;
                break;
            }
            else if (dealer.getTotal() > 21) {
                cout << "Dealer is BUST! House loses!" << endl;
                gameOn = false;
                break;
            }
            cout << player1.getName() << " <H>it or <S>tay or <Q>uit?" << endl;
            cin >> playerInput;
            switch (playerInput) {
            case 'H':
                player1.getCard(true, &deck);
                player1.displayHand();
                break;
            case 'S':
                break;
            case 'Q':
                gameOn = false;
                break;
            default:
                break;
            }
        }
    }

