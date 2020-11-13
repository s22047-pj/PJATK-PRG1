#include <iostream>
#include <random>

auto main() -> int
{
    std::random_device rd;
    std::uniform_int_distribution<int> guess100 (1, 100);

    int x = guess100(rd);

    int user_guess;
    while (true)
    {
        std::cout << "guess: ";
        std::cin >> user_guess;

        if (user_guess == x)
        {
            break;        
        }
        if (user_guess > x) 
        {
            std::cout << "number too big!" << std::endl;
        }   
        else
        {
            std::cout << "number too small!" << std::endl;
        } 
        
    }    
    std::cout << "just right!" << std::endl;

    return 0;
}
