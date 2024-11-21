#pragma once
#include "Card.h"
#include "Suit.h"
class ColorCard : public Card
{
private :
	Suit color;
	int value;
public:
    ColorCard(int value,Suit color) ;
    bool isTrump() override;
    bool isJoker() override;
    bool isColor() override;
    bool isBout() override;
    bool operator==(Card& other)  override;
    void setValue(const int num);
    int getValue() const;
    Suit getColor() const;
    void setColor(const Suit s) ;
    void show();
    ~ColorCard() override = default;
};

