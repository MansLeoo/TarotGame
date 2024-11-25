#include "Game.h"
using namespace std;

Game::Game(vector<shared_ptr<Player>> players) : players(players) , nbPlayer(players.size())
{
    this->initGame();
}
Game::Game() : nbPlayer(0)
{
    this->initGame();
}
void Game::initGame()
{
    CardMaking& make = CardMaking::getInstance();
    CardPack pack = make.createTarotCardPack();
    pack.shuffle();
    this->pack = make_shared<CardPack>(pack);
    this->chien = make_shared<CardPack>(CardPack());
    this->multiplier = 0;
}

void Game::addPlayer(shared_ptr<Player> p) {
    if (this->nbPlayer < 3) {
        this->players.push_back(p);
        this->nbPlayer++;
    }

}
void Game::distributeCards() {
    for (int i = 0; i < 6; i++)
    {
        this->chien->addCard(this->pack->drawCard());
    }
    int turn = 0;
    if (this->nbPlayer = 3) turn = 8;
    if (this->nbPlayer = 4) turn = 6;
    for (int t = 0; t < turn; t++)
    {
        for (const auto& player : players) {
            for (int i = 0; i < 3; i++)
            {
                player->pickCard(this->pack->drawCard());
            }
        }
    }

}
void Game::auction() {
    int index = 0;
    int leaderIndex = 0;
    int leaderPower = 0;
     for (const auto& player : players) {
        std::cout << "C'est au tour de " << player->getName() << "de choisir !";
        printf("Choix possible : \n0 - Passe\n1 - Petite x1 \n2 - Garde x2\n3 - Garde Sans x4\n4 - Garde Contre x6");
        // player choice
        if (playerChoice > leaderPower) {
            leaderPower = playerChoice;
            leaderIndex = index;
        }
        index++;
    }
     if (leaderIndex == 0) {
         //Stop game
     }
     else{
         switch (leaderPower)
         {
         case 1 :
             this->multiplier = 1;
             break;
         case 2:
             this->multiplier = 2;
             break;
         case 3:
             this->multiplier = 4;
             break;
         case 4:
             this->multiplier = 6;
             break;
         default:
             break;
         }


     }
}
