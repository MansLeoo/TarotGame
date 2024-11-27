#include "ComputerPlayer.h"
#include <iostream>
#include <random>

// Constructor for the ComputerPlayer class
// Initializes the computer player with an associated Player object.
ComputerPlayer::ComputerPlayer(std::shared_ptr<Player> p) {
    this->player = p;
}

// Determines the bid level for the computer player based on their hand's strength.
int ComputerPlayer::overbid()
{
    float nbPoint = this->player->getHand()->getPackPoint();
    int nbBout = this->player->getHand()->getNbBout();      

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
    if (nbBout == 1) {
        return 1;
    }
    return 0;
}


std::shared_ptr<Card> ComputerPlayer::playCard(CardPack pack) {
    std::shared_ptr<CardPack> playableCards;

    if (pack.size() == 0) {
        playableCards = this->player->getHand();
    }
    else {
        std::shared_ptr<Card> leadCard = pack.getCards()[0];
        playableCards = this->player->getPlayableCards(leadCard);
    }

    if (playableCards->size() == 0) {
        playableCards = this->player->getHand();
    }

    std::random_device rd;                             // Random number generator device
    std::default_random_engine rng(rd());              // Pseudo-random number generator
    std::uniform_int_distribution<int> dist(0, playableCards->size() - 1); // Distribution range
    int randomIndex = dist(rng);                       // Generate a random index

    // Retrieve the chosen card and remove it from the player's hand.
    auto chosenCard = playableCards->getCards()[randomIndex];
    this->player->getHand()->remove(chosenCard);


    return chosenCard; // Return the chosen card
}
