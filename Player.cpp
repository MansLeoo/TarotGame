#include "Player.h"

std::string Player::getName()
{
    return this->name;
}
CardPack Player::getHand() {
    return this->hand;
}

std::shared_ptr<Strategy> Player::getStrategy()
{
    return this->strategy;
}
void Player::setName(std::string name) {
    this->name = name;
}
void Player::setHand(CardPack pack) {
    this->hand = pack;
}
void Player::setStrategy(std::shared_ptr<Strategy> strat) {
    this->strategy = strat;
}
float Player::getNbPoint()
{
    return this->nbPoint;
}
void Player::pickCard(std::shared_ptr<Card> card){
    this->hand.addCard(card);
    this->hand.sortPack();
}

void Player::setPoint(float nbPoint) {
    this->nbPoint = nbPoint;
}
void Player::addPoint(float nbPoint) {
    this->nbPoint += nbPoint;
}
void Player::removePoint(float nbPoint) {
    this->nbPoint -= nbPoint;
}
void Player::showHand() {
    std::cout << "Jeu de " << this->name << " : " << std::endl;
    this->hand.show();

}
void Player::addTrick(CardPack trick)
{
    for (const auto& card : trick.getCards()) {
        this->trickWin.addCard(card);
    }
}
CardPack Player::getTrick(CardPack trick)
{
    return this->trickWin;
}
Player::Player(std::string name)
{
    this->name = name;
    this->nbPoint = 0;
}
Player::Player(std::string name, std::shared_ptr<Strategy>  strat) : name(name), strategy(strat) {
    this->hand = CardPack();
    this->nbPoint = 0;
}
CardPack Player::getPlayableCards(const std::shared_ptr<Card>& leadCard) {
    CardPack pack;

    // Si la carte menée est l'Excuse, toutes les cartes sont jouables
    if (leadCard->isJoker()) {
        return this->hand;
    }

    // Si la carte menée est un atout
    if (leadCard->isTrump()) {
        auto leaderTrump = std::dynamic_pointer_cast<Trump>(leadCard);

        for (const auto& card : hand.getCards()) {
            if (card->isTrump()) {
                auto trump = std::dynamic_pointer_cast<Trump>(card);
                // Ajouter les atouts plus grands que celui mené
                if (trump->getNumber() > leaderTrump->getNumber()) {
                    pack.addCard(card);
                }
            }
        }

        // Si aucun atout jouable trouvé, toutes les cartes sont jouables
        if (pack.size() != 0) {
            return this->hand;
        }
        return pack;
    }

    // Si la carte menée est une carte de couleur
    if (leadCard->isColor()) {
        auto leaderColorCard = std::dynamic_pointer_cast<ColorCard>(leadCard);
        std::string leadColor = toString(leaderColorCard->getColor());

        // Ajouter les cartes de la couleur demandée
        bool hasColor = false;
        for (const auto& card : hand.getCards()) {
            if (card->isColor()) {
                auto colorCard = std::dynamic_pointer_cast<ColorCard>(card);
                if (toString(colorCard->getColor()) == leadColor) {
                    hasColor = true;
                    pack.addCard(card);
                }
            }
        }

        // Si aucune carte de la couleur demandée
        if (!hasColor) {
            // Ajouter tous les atouts disponibles
            bool hasTrumps = false;
            for (const auto& card : hand.getCards()) {
                if (card->isTrump()) {
                    hasTrumps = true;
                    pack.addCard(card);
                }
            }

            // Si aucun atout disponible, toutes les cartes sont jouables
            if (!hasTrumps) {
                return this->hand;
            }
        }
        return pack;
    }

    // Si aucune règle ne s'applique, toutes les cartes sont jouables
    return this->hand;
}


