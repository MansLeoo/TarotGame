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
    std::cout << "Excuse" << std::endl;
}
