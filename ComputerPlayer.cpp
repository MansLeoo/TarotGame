#include "ComputerPlayer.h"
#include <iostream>
#include <random>
ComputerPlayer::ComputerPlayer(std::shared_ptr<Player>p) {
    this->player = p;
}
int ComputerPlayer::overbid()
{
    float nbPoint = this->player->getHand().getPackPoint();
    int nbBout = this->player->getHand().getNbBout();
    if (nbBout == 3) {
        return 3;
    }
    if (nbBout == 2) {
        if (nbPoint > 40) {
            return 2;
        }
        else {
            return 1;
        }
    }
    if (nbBout == 1)
    {
        return 1;
    }
    return 0;
    
}
std::shared_ptr<Card> ComputerPlayer::playCard(CardPack pack) {
    CardPack playableCards;

    if (pack.size() == 0) {
        // Si aucune carte n'a été menée, toutes les cartes sont jouables
        playableCards = this->player->getHand();
    }
    else {
        // Sinon, déterminer les cartes jouables en fonction de la carte menée
        std::shared_ptr<Card> leadCard = pack.getCards()[0];
        playableCards = this->player->getPlayableCards(leadCard);
    }

    // Si aucune carte n'est jouable selon les règles, jouer n'importe quelle carte de la main
    if (playableCards.size() == 0) {
        playableCards = this->player->getHand();
    }

    // Générer un index aléatoire parmi les cartes jouables
    std::random_device rd;                             // Générateur de nombres aléatoires
    std::default_random_engine rng(rd());              // Moteur de randomisation
    std::uniform_int_distribution<int> dist(0, playableCards.size() - 1); // Distribution entre 0 et la taille des cartes jouables
    int randomIndex = dist(rng);

    // Récupérer la carte choisie aléatoirement
    auto chosenCard = playableCards.getCards()[randomIndex];

    // Retirer la carte choisie de la main de l'ordinateur
    this->player->getHand().remove(chosenCard);

    // Afficher la carte jouée (utile pour suivre le jeu)
    std::cout << this->player->getName() << " a joué : ";
    chosenCard->show();

    // Retourner la carte jouée
    return chosenCard;
}