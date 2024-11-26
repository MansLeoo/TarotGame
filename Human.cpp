#include "Human.h"
#include <iostream>


Human::Human(std::shared_ptr<Player>p) {
    this->player = p;
}
int Human::overbid()
{
    int number = 9;
        while (number < 0 or number > 4) {
            std::cout << "Quel est votre choix ?";
            std::cin >> number;

    }
        return number;

}
std::shared_ptr<Card> Human::playCard(CardPack pack) {
    CardPack playableCards;
    if (pack.size() == 0) {
        playableCards = this->player->getHand();

    }
    else {
        std::shared_ptr<Card> leadCard = pack.getCards()[0];
        // R�cup�rer les cartes jouables selon la logique des r�gles
        CardPack playableCards = this->player->getPlayableCards(leadCard);

    }


    // Afficher les cartes jouables au joueur
    std::cout << "Cartes jouables : " << std::endl;
    int index = 1;
    for (const auto& card : playableCards.getCards()) {
        std::cout << index << ". ";  
        card->show();
        ++index;
    }

    // Choisir une carte � jouer
    int choice = -1;
    while (choice < 1 || choice > playableCards.getCards().size()) {
        std::cout << "Veuillez choisir une carte � jouer (1-" << playableCards.getCards().size() << ") : ";
        std::cin >> choice;

        // V�rifier si l'entr�e est un entier valide
        if (std::cin.fail()) {
            std::cin.clear();             // R�initialise l'�tat du flux
            std::cin.ignore(1000, '\n');  // Ignore les caract�res non valides
            choice = -1;                  // R�initialise la valeur
        }
    }

    // R�cup�rer la carte choisie
    auto chosenCard = playableCards.getCards()[choice - 1];

    // Retirer la carte de la main du joueur
    this->player->getHand().remove(chosenCard);

    // Retourner la carte jou�e
    return chosenCard;
}
