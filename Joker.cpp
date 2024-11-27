#include "Joker.h"
#include <iostream>

Joker::Joker()
{
    this->nbPoint = 4.5;
}

bool Joker::isTrump()
{
    return false;
}

bool Joker::isJoker()
{
    return true;
}

bool Joker::isColor()
{
    return false;
}
bool Joker::isBout()
{
    return true;
}
void Joker::show()
{
    std::cout << "[E:*]" ;
}

bool Joker::operator==( Card& other) 
{
    if (other.isJoker()) {
        return true;
    }
    else {
        return false;
    }
}
bool Joker::BetterThanLeader(std::shared_ptr<Card> card)
{
	return false;
}
