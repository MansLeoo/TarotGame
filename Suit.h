#pragma once
#include <string>

enum class Suit
{
	CLOVER , SPADE , HEART, DIAMONDS
};


inline std::string toString(Suit suit) {
    switch (suit) {
    case Suit::SPADE:   return "♠";
    case Suit::HEART:   return "♥";
    case Suit::DIAMONDS: return "♦";
    case Suit::CLOVER:  return "♣";
    default:            return "Unknown";
    }
}