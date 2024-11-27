#include "CardPack.h"
#include <iostream>
#include <random> 
#include <algorithm>
#include "Joker.h"

CardPack::CardPack()
{
}

// Draws the top card from the pack and removes it from the card list.
std::shared_ptr<Card> CardPack::drawCard()
{
    std::shared_ptr<Card> card = NULL;
    if (this->size() > 0) { // Ensure the pack is not empty
        card = this->cardList.front(); // Take the first card
        cardList.erase(cardList.begin()); // Remove it from the list
    }
    return card;
}

// Draws a specified number of cards from the pack.
std::vector<std::shared_ptr<Card>> CardPack::drawCards(int numberCards)
{
    std::vector<std::shared_ptr<Card>> drawCards;

    for (int i = 0; i < numberCards; ++i) {
        drawCards.push_back(drawCard()); // Add each drawn card to the vector
    }
    return drawCards;
}

// Shuffles the cards in the pack randomly.
void CardPack::shuffle()
{
    std::random_device rd;                    // Generates a random seed
    std::default_random_engine rng(rd());     // Random number generator

    std::shuffle(this->cardList.begin(), this->cardList.end(), rng); // Shuffle cards
}

// Displays all the cards in the pack.
void CardPack::show()
{
    std::cout << "{";
    for (const auto& card : this->cardList) {
        card->show(); 
    }
    std::cout << "}" << std::endl;
}

// Removes a specific card from the pack.
void CardPack::remove(std::shared_ptr<Card> c) {
    for (auto it = this->cardList.begin(); it != this->cardList.end(); ++it) {
        if (*it == c) { // Find the matching card
            this->cardList.erase(it); // Erase the card from the list
            return; // Exit after removing the card
        }
    }
}

// Returns a constant reference to the list of cards.
const std::vector<std::shared_ptr<Card>>& CardPack::getCards() const {
    return this->cardList;
}

// Adds a new card to the pack.
void CardPack::addCard(std::shared_ptr<Card> c)
{
    this->cardList.push_back(c); // Append the card to the pack
}

// Returns the number of cards in the pack.
int CardPack::size()
{
    return this->cardList.size();
}

// Calculates the total points of all cards in the pack.
float CardPack::getPackPoint() {
    float sum = 0.0f;
    for (const auto& card : this->cardList) {
        sum += card->getNbPoint(); // Add the points of each card
    }
    return sum;
}

// Counts the number of "Bouts" in the pack.
int CardPack::getNbBout() {
    int sum = 0;
    for (const auto& card : this->cardList) {
        if (card->isBout()) sum++; // Increment for each "Bout"
    }
    return sum;
}

// Merges another CardPack into the current pack.
void CardPack::mergePack(CardPack pack) {
    for (const auto& card : pack.cardList) {
        this->addCard(card); // Add each card from the other pack
    }
}
CardPack::CardPack(const CardPack& other) {
    for (const auto& card : other.cardList) {
        this->cardList.push_back(card);
    }
}
// Sorts the cards in the pack by type and value.
void CardPack::sortPack() {
    CardPack trumpPack;   // Pack for trump cards
    CardPack heartPack;   // Pack for hearts
    CardPack cloverPack;  // Pack for clovers
    CardPack spadePack;   // Pack for spades
    CardPack diamondPack; // Pack for diamonds
    CardPack jokerPack;   // Pack for jokers

    // Separate cards by type
    for (const auto& card : this->cardList) {
        if (card->isTrump()) {
            trumpPack.addCard(card); // Add to trump pack
        }
        else if (card->isColor()) {
            std::shared_ptr<ColorCard> colorCard = std::dynamic_pointer_cast<ColorCard>(card);
            // Check and add to the corresponding suit pack
            if (colorCard->getColor() == Suit::HEART) {
                heartPack.addCard(card);
            }
            else if (colorCard->getColor() == Suit::CLOVER) {
                cloverPack.addCard(card);
            }
            else if (colorCard->getColor() == Suit::SPADE) {
                spadePack.addCard(card);
            }
            else if (colorCard->getColor() == Suit::DIAMONDS) {
                diamondPack.addCard(card);
            }
        }
        else {
            // Add Joker cards to their own pack
            std::shared_ptr<Joker> jok = std::dynamic_pointer_cast<Joker>(card);
            jokerPack.addCard(jok);
        }
    }

    // Define sorting criteria for trump and color cards
    auto ascendingOrderColorCard = [](const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b) {
        auto cardA = std::dynamic_pointer_cast<ColorCard>(a);
        auto cardB = std::dynamic_pointer_cast<ColorCard>(b);
        return cardA && cardB && cardA->getValue() < cardB->getValue();
        };
    auto ascendingOrderTrumpCard = [](const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b) {
        auto cardA = std::dynamic_pointer_cast<Trump>(a);
        auto cardB = std::dynamic_pointer_cast<Trump>(b);
        return cardA && cardB && cardA->getNumber() < cardB->getNumber();
        };

    // Sort cards in each pack
    std::sort(trumpPack.cardList.begin(), trumpPack.cardList.end(), ascendingOrderTrumpCard);
    std::sort(heartPack.cardList.begin(), heartPack.cardList.end(), ascendingOrderColorCard);
    std::sort(diamondPack.cardList.begin(), diamondPack.cardList.end(), ascendingOrderColorCard);
    std::sort(cloverPack.cardList.begin(), cloverPack.cardList.end(), ascendingOrderColorCard);
    std::sort(spadePack.cardList.begin(), spadePack.cardList.end(), ascendingOrderColorCard);

    // Reassemble the sorted pack
    this->cardList.clear();
    this->cardList.insert(this->cardList.end(), trumpPack.cardList.begin(), trumpPack.cardList.end());
    this->cardList.insert(this->cardList.end(), heartPack.cardList.begin(), heartPack.cardList.end());
    this->cardList.insert(this->cardList.end(), diamondPack.cardList.begin(), diamondPack.cardList.end());
    this->cardList.insert(this->cardList.end(), cloverPack.cardList.begin(), cloverPack.cardList.end());
    this->cardList.insert(this->cardList.end(), spadePack.cardList.begin(), spadePack.cardList.end());
    this->mergePack(jokerPack); // Add jokers to the pack
}
