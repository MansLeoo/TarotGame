#pragma once
#include "CardPack.h"
#include "Strategy.h"
#include <memory>
class Strategy;
class Player
{
protected :
	std::string name;
	std::shared_ptr<CardPack> hand;
	std::shared_ptr<CardPack> trickWin;
	std::shared_ptr<Strategy> strategy;
	float nbPoint;
public :
	Player(std::string name);
	Player(std::string name, std::shared_ptr<Strategy>  strat);
	std::shared_ptr<CardPack> getPlayableCards(const std::shared_ptr<Card>& leadCard);
	void pickCard(std::shared_ptr<Card> card);
	std::string getName();
	std::shared_ptr<CardPack>  getHand();
	std::shared_ptr<Strategy> getStrategy();
	void setName(std::string name);

	void setHand(std::shared_ptr<CardPack>  pack);
	void setStrategy(std::shared_ptr<Strategy> strat);
	float getNbPoint();
	void setPoint(float nbPoint);
	void addPoint(float nbPoint);
	void removePoint(float nbPoint);
	void showHand();
	void addTrick(std::shared_ptr<CardPack> trick);
	std::shared_ptr<CardPack>  getTrick();

};

