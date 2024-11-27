#include <iostream>
#include "CardPack.h"
#include "Card.h"
#include "CardMaking.h"
#include "testCard.h"
#include "testCardPack.h"
#include "Game.h"
#include "Human.h"
#include "ComputerPlayer.h"

#include <windows.h> 
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    testCard();
    testPackCard();

    auto p1 = std::make_shared<Player>("JOUEUR 1");
    auto p2 = std::make_shared<Player>("Ordinateur 1");
    auto p3 = std::make_shared<Player>("JOUEUR 2");

    p1->setStrategy(std::make_shared<Human>(p1));
    p2->setStrategy(std::make_shared<ComputerPlayer>(p2));
    p3->setStrategy(std::make_shared<Human>(p3));

    std::vector<std::shared_ptr<Player>> players = {p1, p2, p3};
    Game g = Game(players);
    g.distributeCards();
    g.auction();
    g.playGame();

}

