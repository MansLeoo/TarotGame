#include <iostream>
#include "Card.h"
#include "Joker.h"
#include "ColorCard.h"
#include "Trump.h"
#include <cassert> 
void static testIsTrump() {
	std::shared_ptr <Card> c = std::make_shared<ColorCard>(10, Suit::CLOVER);
	std::shared_ptr <Card> c2 = std::make_shared<Trump>(10);
	std::shared_ptr <Card> c3 = std::make_shared<Joker>();

	assert(not c3->isTrump());
	assert(not c->isTrump());
	assert(c2->isTrump());

}
 void static testIsColor() {
	 std::shared_ptr <Card> c = std::make_shared<ColorCard>(10, Suit::CLOVER);
	 std::shared_ptr <Card> c2 = std::make_shared<Trump>(10);
	 std::shared_ptr <Card> c3 = std::make_shared<Joker>();

	 assert(not c3->isColor());
	 assert( c->isColor());
	 assert(not c2->isColor());

 }
 void static testIsJoker() {
	 std::shared_ptr <Card> c = std::make_shared<ColorCard>(10, Suit::CLOVER);
	 std::shared_ptr <Card> c2 = std::make_shared<Trump>(10);
	 std::shared_ptr <Card> c3 = std::make_shared<Joker>();

	 assert( c3->isJoker());
	 assert(not c->isJoker());
	 assert(not c2->isJoker());

 }
 void static testIsBout() {
	 std::shared_ptr <Card> c = std::make_shared<ColorCard>(10, Suit::CLOVER);
	 std::shared_ptr <Card> c2 = std::make_shared<Trump>(21);
	 std::shared_ptr <Card> c3 = std::make_shared<Joker>();
	 std::shared_ptr <Card> c4 = std::make_shared<Trump>(15);

	 assert( c3->isBout());
	 assert(not c->isBout());
	 assert(c2->isBout());
	 assert(not  c4->isBout());

 }
 void static testGetNbPoint() {
	 std::shared_ptr <Card> c = std::make_shared<ColorCard>(10, Suit::CLOVER);
	 std::shared_ptr <Card> c2 = std::make_shared<Trump>(21);
	 std::shared_ptr <Card> c3 = std::make_shared<Joker>();
	 std::shared_ptr <Card> c4 = std::make_shared<Trump>(15);
	 std::shared_ptr <Card> c5 = std::make_shared<ColorCard>(11, Suit::CLOVER);
	 std::shared_ptr <Card> c6 = std::make_shared<ColorCard>(12, Suit::CLOVER);
	 std::shared_ptr <Card> c7 = std::make_shared<ColorCard>(13, Suit::CLOVER);
	 std::shared_ptr <Card> c8 = std::make_shared<ColorCard>(14, Suit::CLOVER);

	 assert(c3->getNbPoint() == 4.5);
	 assert(c->getNbPoint() == 0.5);
	 assert(c2->getNbPoint() == 4.5);
	 assert(c4->getNbPoint() == 0.5);
	 assert(c5->getNbPoint() == 1.5);
	 assert(c6->getNbPoint() == 2.5);
	 assert(c7->getNbPoint() == 3.5);
	 assert(c8->getNbPoint() == 4.5);

 }
 void testCard() {
	 testIsJoker();
	 testIsColor();
	 testIsTrump();
	 testIsBout();
	 std::cout << "test Carte [OK]" << std::endl;
 }
