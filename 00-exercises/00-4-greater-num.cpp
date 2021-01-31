#include <iostream>
#include <string>


void compare_val(int const argc, char* argv[])
{
    if (argc < 2 || argc > 3){
        auto error = std::string("please insert two arguments");
        throw std::runtime_error(error);
    }

    auto first_num = std::stod(argv[1]);
    auto second_num = std::stod(argv[2]);

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

auto main(int const argc, char* argv[]) -> int
{
    compare_val(argc, argv);

    return 0;
}