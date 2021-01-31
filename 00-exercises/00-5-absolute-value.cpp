#include <iostream>
#include <string>


auto get_args(int const argc, char* argv[]) -> double
{
    if (argc < 2 || argc > 2){
        auto error = std::string("please insert two arguments");
        throw std::runtime_error(error);
    }

    auto convert_to_double = double{};

    try
    {
        convert_to_double = std::stod(argv[1]);
    }
    catch(const std::exception& e)
    {
        auto error = std::string("please insert a number");
        throw std::runtime_error(error);
    }

    return convert_to_double;
}

void absolute_num(double to_convert)
{
    if (to_convert < 0)
    {
        to_convert = to_convert * -1;
    }
    
    std::cout << to_convert << std::endl;
}

auto main(int const argc, char* argv[]) -> int
{
    auto num_to_convert = get_args(argc, argv);
    absolute_num(num_to_convert);

    return 0;
}