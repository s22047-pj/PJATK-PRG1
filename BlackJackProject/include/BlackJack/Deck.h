#pragma once
#ifndef _DECK_H_
#define _DECK_H_

#include "BlackJack/Card.h"

#include <iostream>
#include <string>
#include <vector>

namespace BlackJack {
class Deck {
public:
    Deck();
    std::vector<Card> deck;

    void print_deck();
    void shulffle();
    BlackJack::Card deal();
    };
}  // namespace BlackJack

#endif