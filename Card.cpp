#include "Card.h"
#include <iostream>
void Card::setNbPoint(float point) {  
    this->nbPoint = point;
}
float Card::getNbPoint() const {
    return this->nbPoint;
}

void Card::loadTexture(const std::string& filePath)
{
    if (!texture.loadFromFile(filePath))
    {
        std::cerr << "Erreur : impossible de charger " << filePath << std::endl;
    }
    else
    {
        this->sprite.setTexture(this->texture);
        this->sprite.setScale(0.5f, 0.5f);
        this->texture.setSmooth(true);
    }
}

void Card::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Card::draw(sf::RenderWindow& window)
{
    window.draw(this->sprite);
}
void Card::setColor(float color) {
    sf::Color originalColor = sprite.getColor();
    sprite.setColor(sf::Color(
        static_cast<sf::Uint8>(originalColor.r * color),
        static_cast<sf::Uint8>(originalColor.g * color),
        static_cast<sf::Uint8>(originalColor.b * color),
        originalColor.a 
    ));

}
