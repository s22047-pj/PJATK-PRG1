#include <iostream>
#include <random>

auto ask_user_for_integer(std::string prompt) -> int
{
    std::cout << prompt;
    auto n = std::string{};
    std::getline(std::cin, n);

    return std::stoi(n);
}

int generate_number()
{
    std::random_device rd;
    std::uniform_int_distribution<int> guess100 (1, 100);
    int random_number = guess100(rd);
    return random_number;
}

void guess_number()
{
    int const num_to_guess = generate_number();
    auto user_guess = int{0};

    while (num_to_guess != user_guess)
    {
        user_guess = ask_user_for_integer("guess: ");

        if (user_guess == num_to_guess)
        {
            break;        
        }
        if (user_guess > num_to_guess) 
        {
            std::cout << "number too big!" << std::endl;
        }   
        else
        {
            std::cout << "number too small!" << std::endl;
        } 
        
    }    
    std::cout << "just right!" << std::endl;
}

auto main() -> int
{
    guess_number();
  
    return 0;
}
