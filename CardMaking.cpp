#include "CardMaking.h"
#include <iostream>
#include "CardPack.h"
#include "Joker.h"
#include <vector>
#include <memory>
std::unique_ptr<CardMaking> CardMaking::instance = nullptr;
CardMaking::CardMaking() {
}

CardMaking& CardMaking::getInstance() {
    if (!instance) {
        instance = std::unique_ptr<CardMaking>(new CardMaking());
    }
    return *instance;
}

CardPack CardMaking::createTarotCardPack() {

    CardPack tarotPack = CardPack();
    // Add Joker in CardPack
    tarotPack.addCard(std::make_shared<Joker>());

    // Add trump in CardPack
    for (int i = 1; i < 22; i++)
    {
        std::shared_ptr <Card> card = std::make_shared<Trump>(i);
        tarotPack.addCard(card);
    }
    // Add Spade Cards in CardPack
    for (int i = 1; i < 15; i++)
    {
        std::shared_ptr <Card> card = std::make_shared<ColorCard>(i,Suit::SPADE);
        tarotPack.addCard(card);
    }
    // Add Diamonds Cards in CardPack
    for (int i = 1; i < 15; i++)
    {
        std::shared_ptr <Card> card = std::make_shared<ColorCard>(i, Suit::DIAMONDS);
        tarotPack.addCard(card);
    }
    // Add Heart Cards in CardPack
    for (int i = 1; i < 15; i++)
    {
        std::shared_ptr <Card> card = std::make_shared<ColorCard>(i, Suit::HEART);
        tarotPack.addCard(card);
    }
    // Add Clover Cards in CardPack
    for (int i = 1; i < 15; i++)
    {
        std::shared_ptr <Card> card = std::make_shared<ColorCard>(i, Suit::CLOVER);
        tarotPack.addCard(card);
    }
    return tarotPack;
}
