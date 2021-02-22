#pragma once
#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
#include <string>

namespace BlackJack {
class Card {
  public:
    Card(std::string, std::string);

    std::string suit;
    std::string rank;

    void print_card();
    std::string card_to_string();
};
}  // namespace BlackJack

#endif