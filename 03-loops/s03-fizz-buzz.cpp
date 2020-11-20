# include <iostream>
# include <string>
# include <vector>

void display_fizz_buzz(std::string user_in)
{
    int user_input = std::stoi(user_in);
    int first_loop = 1;
    while (first_loop < user_input+1)
    {
        std::string user_message[3] = {"Fizz", "Buzz"}; 
        std::string fizz_message;
        std::string buzz_message;       

        if (first_loop % 3 == 0)
        {
            fizz_message = user_message[0];
            none_message = "";
        }
        if (first_loop % 5 == 0)
        {
            buzz_message = user_message[1]; 
            none_message = "";       
        }

        std::cout << first_loop << ": " << fizz_message + buzz_message << std::endl;

        
        first_loop += 1;
    }
}


auto main(int argc , char* argv[]) -> int
{
    try
    {
        if (argc == 0) {
            throw std::string{""};
        }

        display_fizz_buzz(argv[1]);
           

    }
    catch (std::exception const& error)
    {
        std::cerr << ("no argument has been entered: ") << error.what() << '\n';    
    }

    return 1;

}
