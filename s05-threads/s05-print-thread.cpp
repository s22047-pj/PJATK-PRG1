#include <iostream>
#include <thread>


auto print_thread(int ctr) -> void
{
    std::cout << "Hello, " << ctr << "!" << "\n";
}

auto main() -> int
{
    for (auto i = 0; i <= 42; ++i) {
        auto to_pr = std::string{"Hello, "} + std::to_string(i) + "!";
        auto a_thread = std::thread{print_thread, std::move(i)};
        a_thread.detach();
    }
    return 0;
}   