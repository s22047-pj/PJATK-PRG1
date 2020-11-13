# include <iostream>
# include <string>

auto main(int argc , char* argv[]) -> int
{
    try
    {
        if (argc == 0) {
            throw std::string{""};
        }

     

        auto const user_number = std::stoi(argv[1]);
        std::cout << "your number: " << user_number << std::endl;

        if (user_number % 3 == 0 && user_number % 5 == 0)
        {
            std::cout << "FizzBuzz" << std::endl;        
        }

        else if (user_number % 3 == 0)
        {
            std::cout << "Fizz" << std::endl;        
        }

        else if (user_number % 5 == 0)
        {
            std::cout << "Buzz" << std::endl;        
        }


    
    }
    catch (std::exception const& error)
    {
        std::cerr << ("no argument has been entered: ") << error.what() << '\n';    
    }

    return 1;

}
