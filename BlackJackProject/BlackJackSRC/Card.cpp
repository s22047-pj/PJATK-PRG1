#include "BlackJack/Card.h"


BlackJack::Card::Card(std::string suit, std::string rank)
        : suit{suit}, rank{rank}
{}

auto BlackJack::Card::print_card() -> void
{
    std::cout << rank << " of " << suit << std::endl;
}

auto BlackJack::Card::card_to_string() -> std::string
{
    return rank + " " + suit;
}