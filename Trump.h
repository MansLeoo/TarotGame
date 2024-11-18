#pragma once
#include "Card.h"
class Trump : public Card
{
private:
	int number;

public :
    Trump(float point, int number);

    bool CanBePlacedOn(const Card& c) override;
    bool isTrump(const Card& c) override;
    bool isJoker(const Card& c) override;
    bool isColor(const Card& c) override;

    int getNumber() const;
    void setNumber(int num);

    // Destructeur
    ~Trump() override = default;
};

