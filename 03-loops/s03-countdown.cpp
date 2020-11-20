# include <iostream>
# include <string>

auto main(int argc , char* argv[]) -> int
{
    try
    {
        if (argc == 0){
            throw std::string{""};            
        }
        auto const a = std::stoi(argv[1]);
        
        for (int i=a; i>=0; i--)
        {
            std::cout << i << "..." << std::endl;
        }
    }
    catch (std::out_of_range const& error){
        std::cerr << "entred number is too big to handle with it, please run program again and enter smaller number/s: " << error.what() << '\n';    
    }
    catch (std::exception const& error){
        std::cerr << "ERROR : " << error.what();        
    }

    return 1;

}
