#include <iostream>
#include <string>


void compare_val(double first_num, double second_num)
{
    auto grater_num = double{};
    auto smaller_num = double{};

    if (first_num > second_num){
        grater_num = first_num;
        smaller_num = second_num;
    } else {
        grater_num = second_num;
        smaller_num = first_num;
    }

    if (first_num != second_num){
        std::cout << grater_num << " > " << smaller_num << "\n";
    } else {
        std::cout << grater_num << " == " << smaller_num << "\n";
    }
}

auto ask_user_for_num (std ::string const prompt ) -> int
{
    if ( not prompt.empty ()) {
        std::cout << prompt ;
    }

    auto value = std::string{};
    std::getline(std::cin, value);
    auto convert_to_double = double{};

    try
    {
        convert_to_double = std::stod(value);
    }
    catch(const std::exception& e)
    {
        auto error = std::string("please insert a number");
        throw std::runtime_error(error);
    }
    
    return convert_to_double;
}

auto main() -> int
{
    auto f_num = ask_user_for_num("enter a number: ");
    auto s_num = ask_user_for_num("enter a number: ");
    compare_val(f_num, s_num);

    return 0;
}
