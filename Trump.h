#pragma once
#include "Card.h"
class Trump : public Card
{
private:
	int number;

public :
    Trump(int number);

    bool isTrump() override;
    bool isJoker() override;
    bool isColor() override;
    bool isBout() override;
    bool operator==(Card& other)  override;
    void setNumber(const int num);
    int getNumber() const;
    void show();
    ~Trump() override = default;
};

