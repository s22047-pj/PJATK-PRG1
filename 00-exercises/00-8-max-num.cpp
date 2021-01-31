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

    return vector_to_create;
}

void max_num(std::vector <double> vec_get_max)
{
    auto size_to_int = int(vec_get_max.size());

    auto max_num = vec_get_max[0];
    for (int i = 0; i < size_to_int; i++)
    {
        if (max_num < vec_get_max[i])
        {
            max_num = vec_get_max[i];
        }
    }
    
    std::cout << "max num: " << max_num << std::endl;
}

auto main(int argc, char* argv[]) -> int
{
    auto main_vector = get_arguments(argc, argv);
    max_num(main_vector);
    
    return 0;
}
