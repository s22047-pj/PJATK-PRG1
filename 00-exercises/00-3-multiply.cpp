#include <iostream>
#include <string>

auto ask_user_for_integer (std ::string const prompt ) -> int
{
    if ( not prompt.empty ()) {
        std::cout << prompt ;
    }

    auto value = std::string {};
    std::cout << value;
    std::getline (std::cin, value);
    return std::stoi(value);
}

auto main() -> int
{
    auto const first_num = ask_user_for_integer("enter first number: ");
    auto const second_num = ask_user_for_integer("enter first number: ");
    std::cout << "result: " << (first_num * second_num) << "\n";

    return 0;
}
