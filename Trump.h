#pragma once
#include "Card.h"
class Trump : public Card
{
private:
	int number;

public :
    Trump(float point, int number);

    bool isTrump(const Card& c) override;
    bool isJoker(const Card& c) override;
    bool isColor(const Card& c) override;
    void setNumber(const int num);
    int getNumber() const;
    ~Trump() override = default;
};

