#pragma once
#include "Suit.h"
#include <memory>
#include <SFML/Graphics.hpp>

class Card {
protected:
    float nbPoint = 0;
    sf::Texture texture;             
    sf::Sprite sprite;
public:
    virtual bool isTrump() = 0;
    virtual bool isJoker() = 0;
    virtual bool isColor() = 0;
    virtual bool isBout() = 0;
    virtual bool BetterThanLeader(std::shared_ptr<Card> card) = 0;
    void loadTexture(const std::string& filePath);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);
    void setColor(float color);
    virtual bool operator==(Card& other) = 0;
    virtual void show() = 0;
    float  getNbPoint() const ;
    void setNbPoint(float point);
    virtual ~Card() = default;
};

