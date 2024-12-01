#include "CardMaking.h"
#include "CardPack.h"
#include "Joker.h"
#include "Trump.h"
#include "ColorCard.h"
#include <memory>


// Static method to create a tarot card pack
CardPack CardMaking::createTarotCardPack() {
    CardPack tarotPack = CardPack();

    // Add Joker in CardPack
    tarotPack.addCard(std::make_shared<Joker>());
    std::string path;
    // Add Trump cards in CardPack
    for (int i = 1; i < 22; i++) {
        std::shared_ptr<Card> card = std::make_shared<Trump>(i);
        tarotPack.addCard(card);
        path = "img/cards/" + std::to_string(i) + ".png";
        card->loadTexture(path);
    }

    // Add Spade Cards in CardPack
    for (int i = 1; i < 15; i++) {
        std::shared_ptr<Card> card = std::make_shared<ColorCard>(i, Suit::SPADE);
        tarotPack.addCard(card);
        path = "img/cards/" + std::to_string(i) + "Pique.png";
        card->loadTexture(path);
    }

    // Add Diamonds Cards in CardPack
    for (int i = 1; i < 15; i++) {
        std::shared_ptr<Card> card = std::make_shared<ColorCard>(i, Suit::DIAMONDS);
        tarotPack.addCard(card);
        path = "img/cards/" + std::to_string(i) + "Carreau.png";
        card->loadTexture(path);
    }

    // Add Heart Cards in CardPack
    for (int i = 1; i < 15; i++) {
        std::shared_ptr<Card> card = std::make_shared<ColorCard>(i, Suit::HEART);
        tarotPack.addCard(card);
        path = "img/cards/" + std::to_string(i) + "Coeur.png";
        card->loadTexture(path);
    }

    // Add Clover Cards in CardPack
    for (int i = 1; i < 15; i++) {
        std::shared_ptr<Card> card = std::make_shared<ColorCard>(i, Suit::CLOVER);
        tarotPack.addCard(card);
        path = "img/cards/" + std::to_string(i) + "Trefle.png";
        card->loadTexture(path);
    }

    // Return the created tarot card pack
    return tarotPack;
}
