#include <iostream>
#include "CardPack.h"
#include "Card.h"
#include "CardMaking.h"
#include "testCard.h"
int main()
{
    testCard();
    CardMaking& make = CardMaking::getInstance();
    CardPack pack = make.createTarotCardPack() ; 
    pack.show();
    std::cout << "Hello World!\n";
}

