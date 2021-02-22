#include <iostream>
#include "BlackJack/Deck.h"
#include "BlackJack/Hand.h"
#include <string>
#include <vector>
#include <map>
#include <typeinfo>


bool hit_or_stand(BlackJack::Deck& deck, BlackJack::Hand& hand, const std::map <std::string, int>& values, bool playingr)
{
    bool playing = playingr;
    
    while (true)
    {
        char hs_move;
        std::cout << "___________________________________________________\n";
        std::cout << "\nWould you like to Hit or Stand? Enter 'h' or 's': ";
        std::cin >> hs_move;

        if (hs_move == 'h'){
            std::cout << hand.cards.at(1).card_to_string();
            hand.add_card(deck.deal(), values);
            hand.adjust_for_ace();

            playing = true;
        } else if (hs_move == 's') {
            std::cout << "Player stands. Dealer is playing";
            playing = false;
            return playing;
        } else  {
            std::cout << "Sorry, please try again.";
            continue;
        }
        break;
    }
    return playing;
}

void player_busts(BlackJack::Hand hand_player, BlackJack::Hand hand_dealer)
{
    std::cout << "\nBUST PLAYER";
}

void player_wins(BlackJack::Hand hand_player, BlackJack::Hand hand_dealer)
{
    std::cout << "\nPLAYER WINS!";
}

void dealer_busts(BlackJack::Hand hand_player, BlackJack::Hand hand_dealer)
{
    std::cout << "\nPLAYER WINS! DEALER BUSTED!";
}

void dealer_wins(BlackJack::Hand hand_player, BlackJack::Hand hand_dealer)
{
    std::cout << "\nDEALER WINS!";
}

void push(BlackJack::Hand hand_player, BlackJack::Hand hand_dealer)
{
    std::cout << "\nDealer and player tie! PUSH";
}

void show_some(BlackJack::Hand hand_player, BlackJack::Hand hand_dealer)
{
    std::cout << "\nDEALERS HAND:\n";
    std::cout << "<hidden card>\n";
    std::cout << hand_dealer.cards.at(1).card_to_string();
    std::cout << "\n\nPLAYER'S HAND:\n";

    for (auto& card : hand_player.cards)
    {
        std::cout << card.card_to_string() << std::endl;
    }
}

void show_all(BlackJack::Hand hand_player, BlackJack::Hand hand_dealer)
{
    std::cout << "\nDEALERS HAND:\n";
    for (auto card : hand_dealer.cards)
    {
        std::cout << card.card_to_string() << std::endl;
    }
    std::cout << "\n";

    std::cout << "\n\nPLAYER'S HAND\n";
    for (auto card : hand_player.cards)
    {
        std::cout << card.card_to_string() << std::endl;
    }

}


auto main() -> int
{

    auto suits = std::vector <std::string> {"Hearts", "Dimonds", "Spades", "Clubs"};
    auto ranks = std::vector <std::string> {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    auto values = std::map <std::string, int> {{"Two", 2}, {"Three", 3}, {"Four", 4}, {"Five", 5}, {"Six", 6}, {"Seven", 7}, {"Eight", 8}, {"Nine", 9}, {"Queen", 10}, {"King", 10}, {"Ace", 11}};

    while (true)
    {

        
        bool playing = true;

        std::cout << "START\n\n";
        std::cout << "Dealer hits until reaches 17. Aces count as 1 or 11";

        auto deck_of_cards = BlackJack::Deck();
        for (size_t s = 0; s < suits.size(); s++)
        {
            for (size_t r = 0; r < ranks.size(); r++)
            {
                deck_of_cards.deck.push_back(BlackJack::Card{suits[s], ranks[r]});
            }
        }
        deck_of_cards.shulffle();

        auto hand_player = BlackJack::Hand();
        //hand_player.aces = 0;
        hand_player.add_card(deck_of_cards.deal(), values);
        hand_player.add_card(deck_of_cards.deal(), values);

        auto hand_dealer = BlackJack::Hand();
        //hand_dealer.aces = 0;
        hand_dealer.add_card(deck_of_cards.deal(), values);
        hand_dealer.add_card(deck_of_cards.deal(), values);

        show_some(hand_player, hand_dealer);

        while (playing)
        {
            playing = hit_or_stand(deck_of_cards, hand_player, values, playing);

            show_some(hand_player, hand_dealer);
            if (hand_player.value > 21)
            {
                player_busts(hand_player, hand_dealer);
                break;
            }
        }
         
        if (hand_player.value <= 21)
        {
            while (hand_dealer.value < 17)
            {
                hand_dealer.add_card(deck_of_cards.deal(), values);
                hand_dealer.adjust_for_ace();
            }

            show_all(hand_player, hand_dealer);
            
            if (hand_dealer.value > 21)
            {
                dealer_busts(hand_player, hand_dealer);
            } else if (hand_dealer.value > hand_player.value)
            {
                dealer_wins(hand_player, hand_dealer);
            } else if (hand_dealer.value < hand_player.value)
            {
                player_wins(hand_player, hand_dealer);
            } else {
                push(hand_player, hand_dealer);
            }
        }

        std::cout << "To play again enter 'y' to end 'n': ";
        char new_game;
        std::cin >> new_game;

        if (new_game=='y')
        {
            playing=true;
        } else
        {
            std::cout << "\n\nTHX for playing\n";
            break;
        }
         
         
         
    }
    

    return 0;
}