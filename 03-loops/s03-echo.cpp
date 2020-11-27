#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/*
std::vector<std::string> reverse_vector(std::vector<std::string> vector_to_reverse, int argc)
{

    for (int i = argc-1; i > 0; i--) {
        vector_to_reverse.push_back(vector_to_reverse[i]);
        vector_to_reverse.erase(vector_to_reverse.end() - 1);
        std::cout << vector_to_reverse.at(i) << " -reverse" << std::endl;
    }

    return vector_to_reverse;
reverse_vector(main_vector, argc);
}
*/

std::vector<std::string> create_vector(int const argc, char* argv[])
{
    std::vector <std::string> vector_to_create;

    for (int i = 0; i < argc; i++) {
        vector_to_create.push_back(std::string(argv[i]));
        //std::cout << vector_to_create.at(i) << " -reverse" << std::endl;
    }

    vector_to_create.erase(vector_to_create.begin());
    return vector_to_create;
}

auto main(int argc, char* argv[]) -> int
{

    auto main_vector = create_vector(argc, argv);

    std::string new_line = "\n";
    std::string separator = " ";


    for (int i = 0; i < 2; i++)
    {
        if (main_vector.at(i) == "-l")
        {
            separator = "\n";
        }

        if (main_vector.at(i) == "-n")
        {
            new_line = "";
        }

        if (main_vector.at(i) == "-r")
        {
            std::reverse(main_vector.begin(), main_vector.end());
        }
    }



    for (int i = 0; i < int(main_vector.size()); i++)
    {
        std::cout << main_vector.at(i) << separator;
    }

    std::cout << new_line;  
 

    
    return 0;
}
