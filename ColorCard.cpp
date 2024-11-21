#include "ColorCard.h"
#include <iostream>
#include <stdexcept>
ColorCard::ColorCard( int value, Suit color) : value(value) , color(color)
{ 
	if (value > 15 || value < 1) {
		throw std::runtime_error("A Color Card need a value beetween 1 and 15");
	}
	switch(value) {
		case 11 :
			this->nbPoint = 1.5;
			break;
		case 12 : 
			this->nbPoint = 2.5;
			break;
		case 13 :
			this->nbPoint = 3.5;
			break;
		case 14 :
			this->nbPoint = 4.5;
			break;
		default :
			this->nbPoint = 0.5;
			break;
	}
}

bool ColorCard::isTrump()
{
	return false;
}

bool ColorCard::isJoker()
{
	return false;
}

bool ColorCard::isColor()
{
	return true;
}
bool ColorCard::isBout()
{
		return false;
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
bool ColorCard::operator==(Card& other)
{
	if (other.isColor()) {
		ColorCard* color = dynamic_cast< ColorCard*>(&other);
		if (this->value == color->value && this->color == color->color) {
			return true;
		}
	}
	return false;
}
void ColorCard::show()
{
	std::string name = "";
	switch (this->value)
	{
	case  11:
		name = "V" ;
		break;
	case  12:
		name = "C" ;
			break;
	case  13:
		name = "D";
			break;
	case  14:
		name = "K" ;
			break;
	default:
		name = std::to_string(this->value);
		break;
	}
	std::cout << name << " : " << toString(this->color) << std::endl;

}
