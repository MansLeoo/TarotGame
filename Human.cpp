#include "Human.h"
#include <iostream>


Human::Human(std::shared_ptr<Player>p) {
    this->player = p;
}
int Human::overbid()
{   
    int number = 9;
        while (number < 0 or number > 4) {
            this->player->showHand();
            std::cout << "Quel est votre choix ?";
            std::cin >> number;

    }
        return number;

}
std::shared_ptr<Card> Human::playCard(CardPack pack) {
    std::shared_ptr<CardPack> playableCards;
    if (pack.size() == 0) {
        playableCards = this->player->getHand();

    }
    else {
        std::shared_ptr<Card> leadCard = pack.getCards()[0];
        playableCards = this->player->getPlayableCards(leadCard);

    }


    std::cout << "Cartes jouables : " << std::endl;
    int index = 1;
    for (const auto& card : playableCards->getCards()) {
        std::cout << index << ". ";  
        card->show();
        ++index;
    }

    int choice = -1;
    while (choice < 1 || choice > playableCards->getCards().size()) {
        std::cout << "Veuillez choisir une carte à jouer (1-" << playableCards->getCards().size()<< ") : ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();             
            std::cin.ignore(1000, '\n');  
            choice = -1;                  
        }
    }

    auto chosenCard = playableCards->getCards()[choice - 1];

    this->player->getHand()->remove(chosenCard);

    return chosenCard;
}
