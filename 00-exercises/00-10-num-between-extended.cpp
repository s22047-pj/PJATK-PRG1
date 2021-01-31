#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> get_arguments(int const argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        try
        {
            std::stoi(argv[i]);
        }
        catch(const std::exception& e)
        {
            auto error = std::string("array should contains only nums");
            throw std::runtime_error(error);
        }
    }
    
    std::vector <int> vector_to_create;

    for (int i = 1; i < argc; i++) {
        vector_to_create.push_back(std::stod(argv[i]));
    }

    auto size_to_int = int(vector_to_create.size());
    if (size_to_int < 2){
        throw std::runtime_error("enter at least two numbers");
    } else if (size_to_int > 3){
        throw std::runtime_error("enter three numbers");
    } else if (size_to_int == 2){
        vector_to_create.push_back(1);
    } else if (vector_to_create[2] == 0){
        throw std::runtime_error("cant devide by 0");
    }
    

    return vector_to_create;
}

void num_between(std::vector <int> vec_get_max)
{
    for (int i = vec_get_max[0]; i < vec_get_max[1]; i+=1)
    {
        if (i%vec_get_max[2]==0)
        {
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;
}

auto main(int argc, char* argv[]) -> int
{
    auto main_vector = get_arguments(argc, argv);
    num_between(main_vector);
    
    return 0;
}
