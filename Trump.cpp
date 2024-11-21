#include "Trump.h"
#include <iostream>

// Constructeur
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
    std::cout << "L'atout n°" << this->number << " et vaut "  << this->nbPoint <<  " points" << std::endl;
}

void Trump::setNumber(int num) {
    number = num;
}
