#pragma once
#include "CardPack.h"
#include "Strategy.h"
#include <memory>
#include <iostream>

class Human : public Strategy
{
public:
	Human(std::shared_ptr<Player> p);
protected:
	int overbid() ;
	std::shared_ptr<Card> playCard(CardPack pack);
};

