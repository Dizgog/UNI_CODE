#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
class Card
{
public:
    int CardType;
    int jack = 11, queen = 12, king = 13, ace = 14
    int CardColor;
    int Clubs = 15, diamonds = 16, hearts = 17, spades = 18;
    int face;
//public:
    Card(int CardType, int CardColor)
   ~Card();


};

class DeckOfCards
{
    vector<int>
};

class PokerHand
{

   void GiveCards();

};
#endif
