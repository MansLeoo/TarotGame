#include "testCardPack.h"
#include <iostream>
#include "Card.h"
#include "Joker.h"
#include "ColorCard.h"
#include "Trump.h"
#include "CardPack.h"
#include <cassert> 

static void testAddCard() {
	std::shared_ptr <Card> c = std::make_shared<ColorCard>(10, Suit::CLOVER);
	std::shared_ptr <Card> c2 = std::make_shared<Trump>(10);
	std::shared_ptr <Card> c3 = std::make_shared<Joker>();
	CardPack pack = CardPack();
	pack.addCard(c);
	pack.addCard(c2);
	pack.addCard(c3);
	assert(pack.size() == 3);
}
static void testRemoveCard() {
	std::shared_ptr <Card> c = std::make_shared<ColorCard>(10, Suit::CLOVER);
	std::shared_ptr <Card> c2 = std::make_shared<Trump>(10);
	std::shared_ptr <Card> c3 = std::make_shared<Joker>();
	CardPack pack = CardPack();
	pack.addCard(c);
	pack.addCard(c2);
	pack.addCard(c3);
	pack.remove(c);

	assert(pack.size() == 3);
}

void testPackCard() {
	testAddCard();
}