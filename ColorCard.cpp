#include "ColorCard.h"

ColorCard::ColorCard(float point, int value, Suit color) : value(value) , color(color)
{
	setNbPoint(point);
}

bool ColorCard::isTrump(const Card& c)
{
	return false;
}

bool ColorCard::isJoker(const Card& c)
{
	return false;
}

bool ColorCard::isColor(const Card& c)
{
	return true;
}

void ColorCard::setValue(const int num)
{
	this->value = num;
}

int ColorCard::getValue() const
{
	return 0;
}

Suit ColorCard::getColor() const
{
	return Suit();
}

void ColorCard::setColor(const Suit s)
{
	this->color = s;
}
