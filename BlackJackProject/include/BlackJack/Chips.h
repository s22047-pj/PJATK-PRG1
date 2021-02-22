#pragma once
#ifndef _CHIPS_H_
#define _CHIPS_H_

#include <BlackJack/Card.h>
#include <iostream>
#include <string>
#include <vector>

namespace BlackJack {
class Chips {
public:
    Chips();

    int total;
    int bet;

    auto win_bet() -> void;
    auto lose_bet() -> void;
};
}  // namespace BlackJack

#endif