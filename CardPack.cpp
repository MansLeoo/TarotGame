#include "CardPack.h"
#include <iostream>
#include <random> 
#include <algorithm>

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
    std::random_device rd;                    
    std::default_random_engine rng(rd());      

    std::shuffle(this->cardList.begin(),this->cardList.end(), rng);

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

void CardPack::remove(std::shared_ptr<Card> c) {
    for (auto it = this->cardList.begin(); it != this->cardList.end(); ++it) {
        if (*it == c) { 
            this->cardList.erase(it);
            return; 
        }
    }
}
void CardPack::addCard(std::shared_ptr<Card> c)
{
    this->cardList.push_back(c);
}
int CardPack::size()
{
    return this->cardList.size();
}
float CardPack::getPackPoint() {
    float sum = 0.0f;
    for (const auto& card : this->cardList) {
        sum += card->getNbPoint();
    }
    return sum;
}
void CardPack::mergePack(CardPack pack) {
    for (const auto& card : pack.cardList) {
        this->addCard(card);
    }
}
void CardPack::SortPack() {
    CardPack trumpPack;   // Paquet pour les atouts
    CardPack heartPack;   // Paquet pour les cartes de cœur
    CardPack cloverPack;  // Paquet pour les cartes de trèfle
    CardPack spadePack;   // Paquet pour les cartes de pique
    CardPack diamondPack; // Paquet pour les cartes de carreau
    CardPack jokerPack;
    // Sépare les cartes en fonction de leur type
    for (const auto& card : this->cardList) {
        if (card->isTrump()) {
            trumpPack.addCard(card);
        }
        else if (card->isColor()) {
            std::shared_ptr<ColorCard> colorCard = std::dynamic_pointer_cast<ColorCard>(card);

            if (colorCard->getColor() == Suit::HEART) {
                heartPack.addCard(card);
            }
            else if (colorCard->getColor() == Suit::CLOVER) {

                cloverPack.addCard(card);
            }
            else if (colorCard->getColor() == Suit::SPADE) {
                spadePack.addCard(card);
            }
            else if (colorCard->getColor() == Suit::DIAMONDS) {
                diamondPack.addCard(card);
            }
        }

    }

    // Fonction lambda pour trier les cartes dans l'ordre décroissant
    auto descendingOrderColor = [](const std::shared_ptr<ColorCard>& a, const std::shared_ptr<ColorCard>& b) {
        return a->getValue() > b->getValue(); // Assure que les cartes sont triées par valeur décroissante
        };
    auto descendingOrderTrump = [](const std::shared_ptr<Trump>& a, const std::shared_ptr<Trump>& b) {
        return a->getNumber() > b->getNumber(); // Assure que les cartes sont triées par valeur décroissante
        };
    // Trie chaque sous-paquet
    std::sort(trumpPack.cardList.begin(), trumpPack.cardList.end(), descendingOrderTrump);
    std::sort(heartPack.cardList.begin(), heartPack.cardList.end(), descendingOrderColor);
    std::sort(cloverPack.cardList.begin(), cloverPack.cardList.end(), descendingOrderColor);
    std::sort(spadePack.cardList.begin(), spadePack.cardList.end(), descendingOrderColor);
    std::sort(diamondPack.cardList.begin(), diamondPack.cardList.end(), descendingOrderColor);

    // Réassemble le paquet trié
    this->cardList.clear(); 
    this->cardList.insert(this->cardList.end(), trumpPack.cardList.begin(), trumpPack.cardList.end());
    this->cardList.insert(this->cardList.end(), heartPack.cardList.begin(), heartPack.cardList.end());
    this->cardList.insert(this->cardList.end(), cloverPack.cardList.begin(), cloverPack.cardList.end());
    this->cardList.insert(this->cardList.end(), spadePack.cardList.begin(), spadePack.cardList.end());
    this->cardList.insert(this->cardList.end(), diamondPack.cardList.begin(), diamondPack.cardList.end());
}

