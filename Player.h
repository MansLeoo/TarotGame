#pragma once
#include "CardPack.h"
#include "Strategy.h"
#include <memory>
class Player
{
protected :
	std::string name;
	CardPack hand;
	CardPack trickWin;
	std::shared_ptr<Strategy> strategy;
	float nbPoint;
public :
	Player(std::string name);
	Player(std::string name, std::shared_ptr<Strategy>  strat);
	void pickCard(std::shared_ptr<Card> card);
	std::string getName();
	CardPack getHand();
	std::shared_ptr<Strategy> getStrategy();
	void setName(std::string name);

	void setHand(CardPack pack);
	void setStrategy(std::shared_ptr<Strategy> strat);
	float getNbPoint();
	void setPoint(float nbPoint);
	void addPoint(float nbPoint);
	void removePoint(float nbPoint);
	void showHand();
	void addTrick(CardPack trick);
	CardPack getTrick(CardPack trick);

};

