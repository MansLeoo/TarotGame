#include "Player.h"

std::string Player::getName()
{
    return this->name;
}
std::shared_ptr<CardPack> Player::getHand() {
    return this->hand;
}

std::shared_ptr<Strategy> Player::getStrategy()
{
    return this->strategy;
}
void Player::setName(std::string name) {
    this->name = name;
}
void Player::setHand(std::shared_ptr<CardPack> pack) {
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
    this->hand->addCard(card);
    this->hand->sortPack();
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
    this->hand->show();

}
void Player::addTrick(std::shared_ptr<CardPack>  trick)
{
    for (const auto& card : trick->getCards()) {
        this->trickWin->addCard(card);
    }
}
std::shared_ptr<CardPack>  Player::getTrick()
{
    return this->trickWin;
}
Player::Player(std::string name)
{
    this->name = name;
    this->nbPoint = 0;
    this->trickWin = std::make_shared<CardPack>();
    this->hand = std::make_shared<CardPack>();
    
}
Player::Player(std::string name, std::shared_ptr<Strategy>  strat) : name(name), strategy(strat) {
    this->hand = std::make_shared<CardPack>();
    this->nbPoint = 0;
    this->hand = std::make_shared<CardPack>();
    this->trickWin = std::make_shared<CardPack>();
}

// Give a list of playable cards for the current trick
std::shared_ptr<CardPack> Player::getPlayableCards(const std::shared_ptr<Card>& leadCard) {
    CardPack pack;
    if (!leadCard) return  this->hand;
    if (leadCard->isJoker()) {
        return  this->hand;
    }

    if (leadCard->isTrump()) {
        auto leaderTrump = std::dynamic_pointer_cast<Trump>(leadCard);
        for (const auto& card : hand->getCards()) {
            if (card->isTrump()) {
                auto trump = std::dynamic_pointer_cast<Trump>(card);
                if (trump->getNumber() > leaderTrump->getNumber()) {
                    pack.addCard(card);
                }
            }
        }


        if (pack.size() == 0) {
            return this->hand;
        }
        return std::make_shared<CardPack>(pack);
    }
    //if leadCard is a color Card
    if (leadCard->isColor()) {
        auto leaderColorCard = std::dynamic_pointer_cast<ColorCard>(leadCard);
        std::string leadColor = toString(leaderColorCard->getColor());

        bool hasColor = false;
        for (const auto& card : hand->getCards()) {
            if (card->isColor()) {
                auto colorCard = std::dynamic_pointer_cast<ColorCard>(card);
                if (toString(colorCard->getColor()) == leadColor) { // Check if card have the same suit
                    hasColor = true;
                    pack.addCard(card);
                }
            }
        }

        if (!hasColor) {
            bool hasTrumps = false;
            for (const auto& card : hand->getCards()) {
                if (card->isTrump()) {
                    hasTrumps = true;
                    pack.addCard(card);
                }
            }

            if (!hasTrumps) {
                return this->hand;
            }
        }
         return std::make_shared<CardPack>(pack);;
    }

    return this->hand;
}


