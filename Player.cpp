#include "Player.h"

std::string Player::getName()
{
    return this->name;
}
CardPack Player::getHand() {
    return this->hand;
}

Strategy Player::getStrategy()
{
    return this->strategy;
}
void Player::setName(std::string name) {
    this->name = name;
}
void Player::setHand(CardPack pack) {
    this->hand = pack;
}
void Player::setStrategy(Strategy strat) {
    this->strategy = strat;
}
float Player::getNbPoint()
{
    return this->nbPoint;
}
void Player::pickCard(std::shared_ptr<Card> card){
    this->hand.addCard(card);
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
Player::Player(std::string name)
{
    this->name = name;
    this->nbPoint = 0;
}
Player::Player(std::string name, Strategy strat) : name(name), strategy(strat) {
    this->hand = CardPack();
    this->nbPoint = 0;
}

