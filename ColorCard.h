#pragma once
#include "Card.h"
#include "Suit.h"
class ColorCard : Card
{
private :
	Suit color;
	int value;
public:
    ColorCard(float point, int value,Suit color) ;
    bool isTrump(const Card& c) override;
    bool isJoker(const Card& c) override;
    bool isColor(const Card& c) override;
    void setValue(const int num);
    int getValue() const;
    Suit getColor() const;
    void setColor(const Suit s) ;

    ~ColorCard() override = default;
};

