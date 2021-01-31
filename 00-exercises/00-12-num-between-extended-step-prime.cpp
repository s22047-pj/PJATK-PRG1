#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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
    } else if (size_to_int > 4){
        throw std::runtime_error("enter four numbers");
    } else if (size_to_int == 2){
        vector_to_create.push_back(1);
        vector_to_create.push_back(1);
    } else if (size_to_int == 3){
        vector_to_create.push_back(1);
    } else if (vector_to_create[2] == 0){
        throw std::runtime_error("cant devide by 0");
    } else if (vector_to_create[3] == 0){
        throw std::runtime_error("the step cant be 0");
    }

    return vector_to_create;
}

auto check_prime(int p_check) -> int
{
    auto end_arr = (int)sqrt(p_check);
    for (int i = 0; i < end_arr; i++)
    {
        std::cout << i << ", ";
    }

    return p_check;
}

void num_between(std::vector <int> vec_get_max)
{
    auto step = vec_get_max[3];

    if (step > 0)
    {
        for (int i = vec_get_max[0]; i < vec_get_max[1]; i+=step)
        {
            if (i%vec_get_max[2]==0)
            {
                std::cout << i << ", ";
                //check_prime(i);
            }
        }
    } else {
        for (int i = vec_get_max[1]; i > vec_get_max[0]; i+=step)
        {
            if (i%vec_get_max[2]==0)
            {
                std::cout << i << ", ";
            }
        }
    }

    std::cout << std::endl;
}



auto main(int argc, char* argv[]) -> int
{
    auto s = sqrt(3);
    std::cout << s;
    auto main_vector = get_arguments(argc, argv);
    num_between(main_vector);
    
    return 0;
}
