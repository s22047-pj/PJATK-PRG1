#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>



auto main(int argc, char* argv[]) -> int
{
    if (argc == 1) {
        std::cout << "Enter file name" << "\n";
        return 1;
    }

    auto file_name = std::string{argv[1]};
    auto read_from_file = std::ifstream{};
    read_from_file.open(file_name);

    if (!read_from_file)
    {
        std::cerr << "Cannot open a file" << std::endl;
        return 1;
    }
    
    
    auto c = char{};
    while (read_from_file.get(c))
    {
        std::cout << c;
    }
    std::cout << std::endl;
    read_from_file.close();

    return 0;
}