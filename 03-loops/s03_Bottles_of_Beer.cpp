#include <iostream>
#include <string>



auto main(int argc, char* argv[]) -> int
{

  
    int defined_beer_count = 99;

    if (argc > 1)
    {
        defined_beer_count = std::stoi(argv[1]);
    }

    int beer_count = defined_beer_count;
    do {

        std::cout << beer_count << " bottles of beer on thr wall, " << beer_count << " bottles of beer." << std::endl;
        std::cout << "Take one down, pass it around, " << beer_count-1 << " bottles of beer on the wall..."<< std::endl;

        --beer_count;
    } while (beer_count != 0);

    std::cout << "\nNo more bottles of beer on the wall, no more bottles of beer." << std::endl;
    std::cout << "Go to the store and buy some more, 99 on the wall...";

    return 1;
}
