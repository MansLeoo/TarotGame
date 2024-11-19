#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "Trump.h"
#include "ColorCard.h"
class CardPack
{
private :
    std::vector < Card > CardList;
    void Remove(Trump c);
    void Remove(ColorCard c);
    //void Remove(Joker c);
public :
     Card DrawCard();
     std::vector < Card > DrawCards(int numberCards);
     void  Shuffle();
     void Show();
     void Remove(Card c);
};

