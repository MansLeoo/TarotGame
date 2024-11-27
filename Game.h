#pragma once
#include "Card.h"
#include "Player.h"
#include "CardPack.h"
#include <memory>
#include "CardMaking.h"
using namespace std;
class Game
{
private:
    int nbPlayer;
    int indexFirstPlay;
    shared_ptr<CardPack> pack;
    shared_ptr<CardPack> chien;
    shared_ptr<Player> preneur;
    shared_ptr<Player> donneur;
    vector<shared_ptr<Player>> players;
    int multiplier;
public :
    Game();
    Game(vector<shared_ptr<Player>> players);
    void initGame();
    void addPlayer(shared_ptr<Player>);
    void distributeCards();
    void auction();
    int determineWinnerTrick(CardPack trick);
    void playGame();
};

