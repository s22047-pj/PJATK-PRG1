#include <iostream>
#include <string>
#include <vector>

void display_fizz_buzz(std::string user_in)
{
    int user_input = std::stoi(user_in);

    for (int num=1; num < user_input + 1; num++)
    {
        std::string fizz_message;
        std::string buzz_message;

        if (num % 3 == 0) {
            fizz_message = "fizz";
        }
        if (num % 5 == 0) {
            buzz_message = "buzz";
        }

        std::cout << num << ": " << fizz_message + buzz_message << std::endl;
    }

/*
    int num = 1;
    while (num < user_input + 1) {
        std::string fizz_message;
        std::string buzz_message;

        if (num % 3 == 0) {
            fizz_message = "fizz";
        }
        if (num % 5 == 0) {
            buzz_message = "buzz";
        }

        std::cout << num << ": " << fizz_message + buzz_message
                  << std::endl;


        num += 1;
    }
*/

}


auto main(int argc, char* argv[]) -> int
{
    if (argc < 2) {
        throw std::logic_error{"not enaugh arguments"};
    }

    display_fizz_buzz(argv[1]);


    return 0;
}
