#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Card.h"
#include "Trump.h"
#include "ColorCard.h"
class CardPack
{
private :
    std::vector<std::shared_ptr<Card>> cardList;
public :
    std::shared_ptr<Card> drawCard();
     std::vector < std::shared_ptr<Card> > drawCards(int numberCards);
     void  shuffle();
     void show();
     void remove(std::shared_ptr<Card> c);
     void addCard(std::shared_ptr<Card> c);
     int size();
     float getPackPoint();
     void mergePack(CardPack pack);
     void SortPack();
};

