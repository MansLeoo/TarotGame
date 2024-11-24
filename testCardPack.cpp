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
	std::shared_ptr <Card> c4 = std::make_shared<Trump>(20);

	CardPack pack = CardPack();
	pack.addCard(c);
	pack.addCard(c2);
	pack.addCard(c3);
	pack.remove(c);

	assert(pack.size() == 2);
	pack.remove(c2);
	pack.remove(c4);
	assert(pack.size() == 1);

	pack.remove(c3);
	assert(pack.size() == 0);

}
static void testGetNbPoint() {
	std::shared_ptr <Card> c = std::make_shared<ColorCard>(10, Suit::CLOVER);
	std::shared_ptr <Card> c2 = std::make_shared<Trump>(10);
	std::shared_ptr <Card> c3 = std::make_shared<Joker>();
	CardPack pack = CardPack();
	pack.addCard(c);
	pack.addCard(c2);
	pack.addCard(c3);
	assert(pack.getPackPoint() == 5.5f);
}
void testPackCard() {
	testGetNbPoint();
	testRemoveCard();
	testAddCard();
	std::cout << "test PaquetDeCarte [OK]" << std::endl;
}