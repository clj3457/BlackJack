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

        // play game until 21 reached or a player goes bust or all players are done
        while (gameOn) {
           // deal 2 cards to dealer with 1 face up and 1 face down
            dealer.getCard(false, &deck);        // 1st dealer card face down, the rest are face up
            dealer.getCard(true, &deck);
            dealer.displayHand();

            // deal 2 cards face up to player
            player1.getCard(true, &deck);
            player1.getCard(true, &deck);
            player1.displayHand();
            player1.displayTotal();

            // player1 takes a turn
            bool myTurn = true;
            while (myTurn) {
                cout << player1.getName() << " <H>it or <S>tay or <Q>uit?" << endl;
                cin >> playerInput;
                switch (playerInput) {
                case 'H':
                case 'h':
                    player1.getCard(true, &deck);
                    player1.displayHand();
                    player1.displayTotal();
                    break;
                case 'S':
                case 's':
                    myTurn = false;
                    break;
                case 'Q':
                case 'q':
                    gameOn = false;
                    myTurn = false;
                    break;
                default:
                    break;
                }
            }               // end of while myTurn

            // check if dealer needs another card
            while (dealer.evaluateHand() < 17) {
                dealer.getCard(true, &deck);
            }
            if (dealer.evaluateHand() == 21) {
                cout << "Dealer hit 21! House wins!" << endl;
                dealer.showAllCards();
                gameOn = false;
                break;
            }
            else if (dealer.getTotal() > 21) {
                cout << "Dealer is BUST! House loses!" << endl;
                dealer.showAllCards();
                gameOn = false;
                break;
            }

            // evaluate both hands to see who won
            cout << "Dealer has " << dealer.getTotal() << ", ";
            cout << player1.evaluateHand() << " has " << player1.evaluateHand() << "." << endl;
            if (dealer.getTotal() >= player1.getTotal()) {
                cout << "Dealer has WON!" << endl;
            }
            else {
                cout << player1.getName() << " has WON!" << endl;
            }

            // see if we want to play again?
            cout << endl;
            cout << "Play again? <Y>es or <N>o: ";
            cin >> playerInput;
            switch (playerInput) {
            case 'Y':
            case 'y':
                gameOn = true;
                break;
            case 'N':
            case 'n':
                cout << "Bye, bye..." << endl;
                gameOn = false;
                break;
            default:
                cout << "Wrong input! You HAVE to play again to ESCAPE!";
                gameOn = true;
                break;
            }

            if (gameOn) {
                // shuffle the deck and clear players hands
                dealer.clearHand();
                player1.clearHand();
                deck.shuffleDeck();
            }
        }
    }

