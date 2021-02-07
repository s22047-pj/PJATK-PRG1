#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <thread>

auto thread_task(std::queue<std::string>& queue, std::mutex& mtx, int id) -> void
{
    std::random_device rd;
    auto random_num = std::uniform_int_distribution<int>(1, 10);

    while (true) {
        std::lock_guard<std::mutex> lck{mtx};
        if (queue.empty()) {
            auto wait = random_num(rd);
            std::this_thread::sleep_for(std::chrono::milliseconds(wait));

            continue;
        }

        if (!queue.empty()) {
            auto q_val = queue.front();
            queue.pop();
            id = (id+1);

            if (q_val == "") {
                std::cout << "thread " << id << " exit" << std::endl;
                return;
            } else {
                std::cout << "thread: " << id << " val: " << q_val << std::endl;
            }
        }
    }
}

auto main() -> int
{
    std::mutex mtx;

    auto queue = std::queue<std::string>();
    auto enter_text = std::string();

    std::vector<std::unique_ptr<std::thread>> ts;
    for (auto i = 0; i < 4; ++i) {
        auto my_thread = std::make_unique<std::thread>(
            thread_task
            , std::ref(queue)
            , std::ref(mtx)
            , i);
        ts.push_back(std::move(my_thread));
    }


    auto empty_string_num = 0;
    while (true) {
        std::getline(std::cin, enter_text);
        queue.push(enter_text);

        if (enter_text == "") {
            empty_string_num+=1;
        }
        if (empty_string_num == 4) {
            break;
        }
    }

    for (auto& t : ts) {
        t->join();
    }


    return 0;
}