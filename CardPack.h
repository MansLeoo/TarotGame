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
    CardPack();
    std::shared_ptr<Card> drawCard();
     std::vector < std::shared_ptr<Card> > drawCards(int numberCards);
     void  shuffle();
     void show();
     void remove(std::shared_ptr<Card> c);
     const std::vector<std::shared_ptr<Card>>& getCards() const;
     void addCard(std::shared_ptr<Card> c);
     int size();
     float getPackPoint();
     int getNbBout();
     void mergePack(CardPack pack);
     CardPack(const CardPack& other);
     void sortPack();
     void showGraphicCard(float x, float y, sf::RenderWindow& window);
};

