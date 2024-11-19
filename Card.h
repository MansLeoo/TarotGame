#pragma once
#include "Suit.h"
class Card {
private:
    float nbPoint;

public:
    virtual bool isTrump(const Card& c) = 0;
    virtual bool isJoker(const Card& c) = 0;
    virtual bool isColor(const Card& c) = 0;
    float  getNbPoint() const ;
    void setNbPoint(float point);
    virtual ~Card() = default;
};

