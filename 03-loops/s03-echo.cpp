#include <iostream>
#include <string>
#include <vector>

auto arr_reverse(int argc, std::string(char* argv_in[])) -> std::string
{
    std::string argv_rev[2];
    for (int i=argc; i > 1; i--)
    {
        argv_rev[i] = argv_in[i];
    }  

    return 
}

auto main(int argc, char* argv[]) -> int
{

    if (argc == 0) {
        return 1;
    }

    auto new_line = std::string{"\n"};
    auto separator = std::string{" "};

    if (std::string{argv[1]} == "-n")
    {
        new_line = "";    
    }  

    if (std::string{argv[1]} == "-l")
    {
        separator = "\n";    
    } 

    if (std::string{argv[1]} == "-r")
    {
        for (int i=argc; i > 1; i--)
        {
            std::cout << argv[i] << separator;
        }    
    } 

    for (int i=1; i < argc; i++)
    {
        std::cout << argv[i] << separator;
    }

    std::cout << new_line;


    return 0;
}
