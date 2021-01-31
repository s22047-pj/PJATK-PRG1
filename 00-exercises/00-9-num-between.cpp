#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<double> get_arguments(int const argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        try
        {
            std::stod(argv[i]);
        }
        catch(const std::exception& e)
        {
            auto error = std::string("array should contains only nums");
            throw std::runtime_error(error);
        }
    }
    
    std::vector <double> vector_to_create;

    for (int i = 1; i < argc; i++) {
        vector_to_create.push_back(std::stod(argv[i]));
    }

    auto size_to_int = int(vector_to_create.size());
    if (size_to_int != 2)
    {
        throw std::runtime_error("enter two numbers");
    }
    

    return vector_to_create;
}

void num_between(std::vector <double> vec_get_max)
{
    for (double i = vec_get_max[0]; i < vec_get_max[1]; i+=0.1)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

auto main(int argc, char* argv[]) -> int
{
    auto main_vector = get_arguments(argc, argv);
    num_between(main_vector);
    
    return 0;
}
