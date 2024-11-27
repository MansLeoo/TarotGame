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

// Method to initialize the game (card pack, chien, multiplier, etc.)
void Game::initGame()
{
    CardPack pack = CardMaking::createTarotCardPack();
    pack.shuffle();
    this->pack = make_shared<CardPack>(pack);
    this->chien = make_shared<CardPack>(CardPack());
    this->multiplier = 0;
    this->indexFirstPlay = 0;
}
// Method to add a player to the game
void Game::addPlayer(shared_ptr<Player> p) {
        this->players.push_back(p);
        this->nbPlayer++;



}
// Method to distribute cards to the players and "chien"
void Game::distributeCards() {

    for (int i = 0; i < 6; i++)
    {
        this->chien->addCard(this->pack->drawCard());
    }
    int turn = 0;
    if (this->nbPlayer == 3) turn = 8;
    if (this->nbPlayer == 4) turn = 6;
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
// Auction phase where players choose their bid (e.g., Petit, Garde, etc.)
void Game::auction() {
    int index = 0;
    int leaderIndex = 0;
    int leaderPower = 0;
     for (const auto& player : players) {
        std::cout << "C'est au tour de " << player->getName() << " de choisir !";
        printf("Choix possible : \n0 - Passe\n1 - Petite x1 \n2 - Garde x2\n3 - Garde Sans x4\n4 - Garde Contre x6\n");
        int playerChoice = player->getStrategy()->overbid();
        if (playerChoice > leaderPower) {
            leaderPower = playerChoice;
            leaderIndex = index;
        }
        printf("\n%i \n", leaderPower);
        switch (leaderPower)
        {
        case 1:
            std::cout << player->getName() << " a choisi de  faire une petite !" << std::endl;
            break;
        case 2:
            std::cout << player->getName() << " a choisi de  faire une garde !" << std::endl;
            break;
        case 3:
            std::cout << player->getName() << " a choisi de  faire une garde sans !" << std::endl;
            break;
        case 4:
            std::cout << player->getName() << " a choisi de  faire une garde contre !" << std::endl;
            break;
        case 0:
            std::cout << player->getName() << " a choisi de passer !" << std::endl;
            break;
        }
        index++;
    }
     if (leaderIndex == 0) {
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
     std::cout << "L'attaquant sera : " << this->players[leaderIndex]->getName() << " !" << std::endl;
     this->indexFirstPlay = leaderIndex;
}

// Give the index player of Trick winner
int Game::determineWinnerTrick(CardPack trick) {
    auto playedCards = trick.getCards();
    int winnerIndex = this->indexFirstPlay;
    shared_ptr<Card> leaderCard = playedCards[0];
    for (int i = 1; i < playedCards.size() ; i++)
    {
        if (not leaderCard->BetterThanLeader(playedCards[i])) {
            leaderCard = playedCards[i];
            winnerIndex++;
        }


    }
    if (winnerIndex >= 3) winnerIndex = winnerIndex % this->nbPlayer;
    this->indexFirstPlay = winnerIndex;
    return winnerIndex; 
}
// Start the game loop
void Game::playGame() {

    int currentPlayerIndex = this->indexFirstPlay; 
    int numberOfTricks = 0 ;
    if (this->nbPlayer == 3)  numberOfTricks = 24;
    if (this->nbPlayer == 4)  numberOfTricks = 18;


    for (int trick = 0; trick < numberOfTricks; ++trick) {
        std::cout << "Tour de jeu : " << trick + 1 << "/" << numberOfTricks << std::endl;

        CardPack currentTrick;

        for (int i = 0; i < this->nbPlayer; ++i) {
            std::cout << std::endl <<  "Plis actuel : ";
            currentTrick.show();
            auto currentPlayer = this->players[currentPlayerIndex];
            //show currentPlayerHand
            currentPlayer->showHand();
            auto playedCard = currentPlayer->getStrategy()->playCard(currentTrick);

            currentTrick.addCard(playedCard);

            std::cout << currentPlayer->getName() << " joue : ";
            playedCard->show();

            currentPlayerIndex = (currentPlayerIndex + 1) % this->nbPlayer ; 
        }

        int winnerIndex = determineWinnerTrick(currentTrick);

        currentTrick.show();
        std::cout << "Le gagnant du pli est : " << this->players[winnerIndex]->getName() << " !" << std::endl;

        for (const auto& card : currentTrick.getCards()) {
            this->players[winnerIndex]->getTrick()->addCard(card);
        }

        currentPlayerIndex = winnerIndex;
    }

    std::cout << "\nPartie terminée ! Voici les résultats :\n";
    for (int i = 0; i < this->nbPlayer; ++i) {
        std::cout << this->players[i]->getName() << " : " << this->players[i]->getTrick()->getPackPoint() << " points." << std::endl;
    }

}

