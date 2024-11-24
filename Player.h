#pragma once
#include "CardPack.h"
#include "Strategy.h"
class Player
{
protected :
	std::string name;
	CardPack hand;
	Strategy strategy;
	float nbPoint;
public :
	Player(std::string name, Strategy strat);
	std::string getName();
	CardPack getHand();
	Strategy getStrategy();
	void setName(std::string name);
	void setHand(CardPack pack);
	void setStrategy(Strategy strat);
	float getNbPoint();
	void setPoint(float nbPoint);
	void addPoint(float nbPoint);
	void removePoint(float nbPoint);

};

