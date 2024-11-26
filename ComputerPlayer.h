#pragma once
#include "Strategy.h"
class ComputerPlayer : public Strategy
{
public :
	ComputerPlayer(std::shared_ptr<Player> p);
private :
	int overbid()  ;

	std::shared_ptr<Card> playCard(CardPack pack);

};

