#include "Trump.h"
#include <iostream>

Trump::Trump(int number) : number(number) {
    if (number > 21 || number < 1) {
        throw std::runtime_error("A Trump need a value beetween 1 and 15");
    }
    if (number == 21 or number == 1) {
        this->nbPoint = 4.5;
    }
    else {
        this->nbPoint = 0.5;
    }
}



bool Trump::isTrump() {
    return true;
}

bool Trump::isJoker() {
    return false;
}

bool Trump::isColor() {
    return false;
}

bool Trump::isBout()
{
    if (number == 21 or number == 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Trump::operator==(Card& other)
{
    if (other.isTrump()) {
         Trump* trump = dynamic_cast< Trump*>(&other);
         if (this->number == trump->number) {
             return true;
         }
    }
    return false;
}

int Trump::getNumber() const {
    return number;
}

void Trump::show()
{
    std::cout << "[A-" << this->number << "]";
}

void Trump::setNumber(int num) {
    number = num;
}
bool Trump::BetterThanLeader(std::shared_ptr<Card> card)
{
    if (card->isColor()) return true;
    if (card->isJoker()) return true;
    if (card->isTrump()) {
        auto trump = std::dynamic_pointer_cast<Trump>(card);
            if (trump->getNumber() > this->number) return false;
            return true;
        
    }
    return false;
}