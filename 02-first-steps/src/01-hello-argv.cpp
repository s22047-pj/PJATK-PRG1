/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>

auto get_argument(int const argc, char* argv[], int const n) -> std::string
{
    if (n >= argc)
    {
        throw std::logic_error{"not enaugh arguments"};    
    }
    return std::string{argv[n]};
}

auto main(int argc, char* argv[]) -> int
{
    try{
        auto const name = get_argument(argc, argv, 1);
        std::cout << "Hello, " << name << "!\n";
    }
    catch (std::string nothing)
    {
        std::cout << nothing;    
    }

    return 0;
}
