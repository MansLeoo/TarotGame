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
void Player::setPoint(float nbPoint) {
    this->nbPoint = nbPoint;
}
void Player::addPoint(float nbPoint) {
    this->nbPoint += nbPoint;
}
void Player::removePoint(float nbPoint) {
    this->nbPoint -= nbPoint;
}
Player::Player(std::string name, Strategy strat) : name(name), strategy(strat) {
    this->hand = CardPack();
}

