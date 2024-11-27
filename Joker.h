#pragma once
#include "Card.h"
#include <iostream>

class Joker : public Card
{

public:

	Joker() ;
	bool isTrump() override;
	bool isJoker() override;
	bool isColor() override;
	bool isBout() override;

	void show() override;
	bool operator==(Card& other)  override;

	bool BetterThanLeader(std::shared_ptr<Card> card);

};

