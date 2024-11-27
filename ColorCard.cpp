#include "ColorCard.h"
#include <iostream>
#include <stdexcept>

// Constructor for the ColorCard class
// Initializes a color card with a value and a suit (color).
ColorCard::ColorCard(int value, Suit color) : value(value), color(color)
{
    // Ensure the card value is between 1 and 15.
    if (value > 15 || value < 1) {
        throw std::runtime_error("A Color Card must have a value between 1 and 15");
    }

    // Assign points based on the card's value.
    switch (value) {
    case 11:
        this->nbPoint = 1.5; // Jack
        break;
    case 12:
        this->nbPoint = 2.5; // Knight
        break;
    case 13:
        this->nbPoint = 3.5; // Queen
        break;
    case 14:
        this->nbPoint = 4.5; // King
        break;
    default:
        this->nbPoint = 0.5; // Numeric cards
        break;
    }
}

// Method to indicate that this card is not a Trump card.
bool ColorCard::isTrump()
{
    return false;
}

// Method to indicate that this card is not a Joker.
bool ColorCard::isJoker()
{
    return false;
}

// Method to indicate that this card is a Color card.
bool ColorCard::isColor()
{
    return true;
}

// Method to indicate that this card is not a "Bout" card.
bool ColorCard::isBout()
{
    return false;
}

// Sets the card's value.
void ColorCard::setValue(const int num)
{
    this->value = num;
}

// Returns the card's value.
int ColorCard::getValue() const
{
    return this->value;
}

// Returns the card's suit (color).
Suit ColorCard::getColor() const
{
    return this->color;
}

// Sets the card's suit (color).
void ColorCard::setColor(const Suit s)
{
    this->color = s;
}

// Equality operator: compares this card with another card.
bool ColorCard::operator==(Card& other)
{
    // Check if the other card is also a Color card.
    if (other.isColor()) {
        ColorCard* color = dynamic_cast<ColorCard*>(&other);
        // Compare the value and the color of both cards.
        if (this->value == color->value && this->color == color->color) {
            return true;
        }
    }
    return false;
}

// Displays the card's details.
void ColorCard::show()
{
    std::string name = "";
    switch (this->value)
    {
    case 11:
        name = "V"; // Jack
        break;
    case 12:
        name = "C"; // Knight
        break;
    case 13:
        name = "Q"; // Queen
        break;
    case 14:
        name = "K"; // King
        break;
    default:
        name = std::to_string(this->value); // Numeric cards
        break;
    }
    std::cout << "[" << name << ":" << toString(this->color) << "]";
}

// Compares this card with another card to determine if it is "better" (wins the trick).
bool ColorCard::BetterThanLeader(std::shared_ptr<Card> card)
{
    // If the leader card is a Trump, this card cannot be better.
    if (card->isTrump()) return false;

    // If the leader card is a Joker, this card loses to the Joker.
    if (card->isJoker()) return false;

    // If the leader card is a Color card:
    if (card->isColor()) {
        std::cout << "Je compare";
        card->show();
        std::cout << "et";
        this->show();
        auto colorCard = std::dynamic_pointer_cast<ColorCard>(card);
        // If the suits do not match, this card cannot win.
        if (toString(this->color) != toString(colorCard->getColor())) {
            return false;
        }
        else {
            // Compare values if the suits are the same.
            if (colorCard->getValue() > this->value) {
                std::cout << "LEADER : ";
                colorCard->show();
                return false; // Leader card has a higher value.
            }
            std::cout << "LEADER : ";
            this->show();
            return true; // This card wins.
        }
    }

    return false;
}
