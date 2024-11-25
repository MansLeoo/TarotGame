#pragma once
#include "Card.h"
#include "Player.h"
#include "CardPack.h"
#include <memory>
using namespace std;

class Team {
private :
		vector<shared_ptr<Player> > playerList;
		float nbPoint;
		int nbBouts;

public:

};