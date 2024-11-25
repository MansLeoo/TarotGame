#pragma once
#include "CardPack.h"
#include "Strategy.h"
#include <memory>
#include <iostream>

class Human : public Strategy
{
	int overbid();
};

