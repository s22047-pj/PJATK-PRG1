#include <chrono>
#include <iostream>
#include <thread>
#include <string>

#include <itp/channel.h>



auto printer(itp::channel<std::string>& ch, int id) -> void
{
    std::cout << "printer is running!\n";

    while (true)
    {
        auto message = ch.wait();

        if (message.empty())
        {
            std::cout << "thread number " << id << " exit\n";
            break;
        }

        if (!message.empty())
        {
            std::cout << "from thread number " << id << ": " << message << " exit\n";
            try{
                message = ch.wait_for(std::chrono::milliseconds{324});
            } catch (itp::timeout_expired_error const&) {
            }
        }
    
        std::cout << "printer is shutting down!\n";
    }
}



auto main() -> int
{
    auto ch = itp::channel<std::string>{};
    //auto th = std::thread{printer, std::ref(ch)};

    auto th0 = std::thread{printer, std::ref(ch)};
    auto th1 = std::thread{printer, std::ref(ch)};
    auto th2 = std::thread{printer, std::ref(ch)};
    auto th3 = std::thread{printer, std::ref(ch)};

    auto empty_string_num = 0;
    while (true) {
        auto enter_text = std::string{};
        std::getline(std::cin, enter_text);

        if (enter_text == "") {
            empty_string_num+=1;
        }

        ch.push(enter_text);

        if (empty_string_num == 4) {
            break;
        }
    }


    th0.join();
    th1.join();
    th2.join();
    th3.join();

    return 0;
}


    // {
    //     auto message = std::string{};
    //     do
    //     {
    //         std::getline(std::cin, message);
    //         ch.push(message);
    //     } while (not message.empty());
    // }