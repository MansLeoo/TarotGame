#pragma once
#include "Strategy.h"
class ComputerPlayer : public Strategy
{
	ComputerPlayer(std::shared_ptr<Player> p);
	int overbid()  ;

};

