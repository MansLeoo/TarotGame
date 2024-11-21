#pragma once
#include "Suit.h"
class Card {
protected:
    float nbPoint = 0;

public:
    virtual bool isTrump() = 0;
    virtual bool isJoker() = 0;
    virtual bool isColor() = 0;
    virtual bool isBout() = 0;
    virtual bool operator==(Card& other) = 0;
    virtual void show() = 0;
    float  getNbPoint() const ;
    void setNbPoint(float point);
    virtual ~Card() = default;
};

