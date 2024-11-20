#pragma once
#include <string>

enum class Suit
{
	CLOVER , SPADE , HEART, DIAMONDS
};


inline std::string toString(Suit suit) {
    switch (suit) {
    case Suit::SPADE:   return "Pique";
    case Suit::HEART:   return "Coeur";
    case Suit::DIAMONDS: return "Carreau";
    case Suit::CLOVER:  return "Trefle";
    default:            return "Unknown";
    }
}