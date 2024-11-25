#include <iostream>
#include "CardPack.h"
#include "Card.h"
#include "CardMaking.h"
#include "testCard.h"
#include "testCardPack.h"
#include "Game.h"
#include <windows.h> 
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    testCard();
    testPackCard();


    Player p1 = Player("Bob");
    Player p2 = Player("Michel");
    Player p3 = Player("Vero");

    vector<shared_ptr<Player>> players;

    players.push_back(make_shared<Player>(p1));
    players.push_back(make_shared<Player>(p2));
    players.push_back(make_shared<Player>(p3));
    Game g = Game(players);
    g.distributeCards();
    players[0]->showHand();
    players[1]->showHand();
    players[2]->showHand();


    std::cout << "a = éé";

    std::cout << "Hello World!\n";
}

