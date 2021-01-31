#include <iostream>
#include <string>


auto get_val(int const argc, char* argv[]) -> double
{
    if (argc < 2 || argc > 2){
        auto error = std::string("please insert one argument");
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

void check_sign(double num_to_check)
{
    auto result = std::string{};
    if (num_to_check > 0)
    {
        result = "1";
    } else if (num_to_check < 0){
        result = "-1";
    } else {
        result = "0";
    }

    std::cout << result << std::endl;   
}

auto main(int const argc, char* argv[]) -> int
{
    auto arg_num = get_val(argc, argv);
    check_sign(arg_num);

    return 0;
}