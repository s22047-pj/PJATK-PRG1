#include "BlackJack/Chips.h"
#include <iostream>
BlackJack::Chips::Chips()
    :total{total=100}
    , bet{bet=0}
{}

void BlackJack::Chips::win_bet()
{
    total += bet;
}

void BlackJack::Chips::lose_bet()
{
    total -= bet;
}

