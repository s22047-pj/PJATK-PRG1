# include <iostream>
# include <string>
# include <vector>

auto main(int argc, char* argv[]) -> int
{
    if(argc < 2)
    {
        throw std::logic_error{"not enaugh arguments"}; 
    }

    std::vector <std::string> args;
    for (int i=1; i < argc; i++)
    {
        args.push_back(argv[i]);
    }
   
    try
    {
        int sum = 0;
        for (uint i=0; i < args.size(); i++)
        {
            sum += std::stoi(args.at(i));
        }
        std::cout << "suma podamych liczb: " << sum << std::endl;
    }
    catch (std::out_of_range const& error){
        std::cerr << "entred number is too big to handle with it, please run program again and enter smaller number/s: " << error.what() << '\n';    
    }

    return 0;
}
