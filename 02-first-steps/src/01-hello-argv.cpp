/*
 * Reading command line arguments.
 */

#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    try
    {
        if (argc == 0) {
            throw std::string{""};
        }
        auto const name = std::string{argv[1]};
        std::cout << "Hello, " << name << "!\n";
    }
    catch (std::exception const& error)
    {
        std::cerr << ("no argument has been entered: ") << error.what() << '\n';    
    }

    return 0;
}
