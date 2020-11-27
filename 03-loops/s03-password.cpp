#include <iostream>
#include <string>

auto get_argument(int const argc, char* argv[], int const n) -> std::string
{
    if (n >= argc) {
        throw std::logic_error{"not enaugh arguments"};
    }
    return std::string{argv[n]};
}

auto ask_user_for_password(std::string prompt) -> std::string
{
    std::cout << prompt;
    auto n = std::string{};
    std::getline(std::cin, n);

    return n;
}

auto main(int const argc, char* argv[]) -> int
{
    auto const defined_password = get_argument(argc, argv, 1);
    std::string user_password;

    while (defined_password != user_password) {
        user_password = ask_user_for_password("enter password: ");
    }

    std::cout << "you guessed it!" << std::endl;
    return 0;
}
