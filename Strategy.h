#pragma once
#include "Player.h"

class Player;

class Strategy
{
public:
	virtual int overbid() = 0;
	virtual std::shared_ptr<Card> playCard(CardPack pack) = 0;

protected:
	std::shared_ptr<Player> player;

};

