#include "Trump.h"

// Constructeur
Trump::Trump(float point, int number) : number(number) {
    setNbPoint(point);  
}



bool Trump::isTrump(const Card& c) {
    return true;
}

bool Trump::isJoker(const Card& c) {
    return false;
}

bool Trump::isColor(const Card& c) {
    return false;
}

int Trump::getNumber() const {
    return number;
}

void Trump::setNumber(int num) {
    number = num;
}
