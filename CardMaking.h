#pragma once
#include <memory>
#include "CardPack.h"
#include <vector>
#include <memory>

class CardMaking {
private:
    static std::unique_ptr<CardMaking> instance;
    CardMaking();

public:
    CardMaking(const CardMaking&) = delete;
    static CardMaking& getInstance();
    CardPack createTarotCardPack();
    ~CardMaking() = default;
};

