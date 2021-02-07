#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <thread>
#include <condition_variable>


auto handle_task(std::queue<std::string>& queue, std::mutex& mtx, std::condition_variable& cv, int id) -> void
{
    std::random_device rd;
    auto random_num = std::uniform_int_distribution<int> (1, 100);

    while (true) {
        auto lck =  std::unique_lock<std::mutex>{mtx};
        cv.wait(lck);

        if (queue.empty()) {
            auto wait_t = random_num(rd);
            std::this_thread::sleep_for(std::chrono::milliseconds(wait_t));

            continue;
        }

        if (!queue.empty()) {
            auto q_val = queue.front();
            queue.pop();

            if (q_val == "") {
                std::cout << "thread " << id << std::endl;
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

    std::condition_variable cv;
    auto const thread_c = 2;

    std::vector<std::unique_ptr<std::thread>> ts;
    for (auto i = 0; i < thread_c; ++i) {
        auto my_thread = std::make_unique<std::thread>(
            handle_task,
            std::ref(queue),
            std::ref(mtx),
            std::ref(cv),
            i + 1);
        ts.push_back(std::move(my_thread));
    }


    auto empty_string_counter = 0;
    while (true) {
        std::getline(std::cin, enter_text);
        queue.push(enter_text);

        if (enter_text == "") {
            empty_string_counter+=1;
        }

        cv.notify_one();
        if (empty_string_counter == thread_c) {
            break;
        }
    }


    for (auto& t : ts) {
        t->join();
    }


    return 0;
}