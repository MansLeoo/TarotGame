#include "CardPack.h"
#include <iostream>

std::shared_ptr<Card> CardPack::drawCard()
{
    std::shared_ptr<Card> card = NULL;
    if (this->size() > 0) {
         card = this->cardList.front();
        cardList.erase(cardList.begin());
    }
	return card;
}

std::vector<std::shared_ptr<Card>> CardPack::drawCards(int numberCards)
{
    std::vector<std::shared_ptr<Card>> drawCards;

    for (int i = 0; i < numberCards; ++i) {
        drawCards.push_back(drawCard());
    }
    return drawCards;
}

void CardPack::shuffle()
{
}

void CardPack::show()
{
    std::cout << "Le paquet a comme carte :" << std::endl;
    for (const auto& card : this->cardList) {
        if (card->isBout()) {
            std::cout << "[bout]";
        }
        card->show(); 

    }
}

void CardPack::remove(std::shared_ptr<Card> c)
{
}
void CardPack::addCard(std::shared_ptr<Card> c)
{
    this->cardList.push_back(c);
}
int CardPack::size()
{
    return this->cardList.size();
}

