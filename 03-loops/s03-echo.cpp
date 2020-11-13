#include <iostream>
#include <string>


auto main(int argc, char* argv[]) -> int
{
    try
    {
        auto new_line = "\n";

        if (argc == 0) {
            throw std::string{""};
        }

        if (std::string{argv[1]} == "-n")
        {
            for (int i=0; i<argc; i++)
            {
                std::cout << std::string{argv[i]} << ", ";
            }           
        }  

        else if (std::string{argv[1]} == "-l")
        {
            for (int i=0; i<argc; i++)
            {
                std::cout << std::string{argv[i]} << std::endl;
            }
        }

        else if (std::string{argv[1]} == "-r")
        {
            for (int i=argc; i>0; i--)
            {
                std::cout << std::string{argv[i]} << ", ";
            }                  
        }

        std::cout << new_line;

    }
    catch (std::exception const& error)
    {
        std::cerr << ("no argument has been entered: ") << error.what() << '\n';    
    }

    return 0;
}
