#include "Trump.h"

// Constructeur
Trump::Trump(float point, int number) : number(number) {
    setNbPoint(point);  // Appel de la m�thode de la classe de base pour d�finir les points
}

// Impl�mentation de CanBePlacedOn
bool Trump::CanBePlacedOn(const Card& c) {
    // Exemple simple : une carte atout peut �tre pos�e sur une autre carte atout
    return c.isTrump(c);
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
