#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <string>

auto take_value_from_queue(std::queue<int>& queue, std::mutex& mtx, int id) -> void
{
    while (true) {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        std::lock_guard<std::mutex> lck{mtx};
        if (queue.empty()) {
            return;
        }
        std::cout << "thread: " << id << "queue: " << queue.front() << std::endl;
        queue.pop();
        id = (id+1);
    }
}

auto main() -> int
{
    std::mutex mtx;

    auto queue = std::queue<int>();
    for (auto i = 1; i <= 100; ++i) {
        queue.push(i);
    }

    auto ts = std::vector<std::unique_ptr<std::thread>>{};

    for (auto i = 0; i <= 4; ++i) {
        auto thread = std::make_unique<std::thread>(
            take_value_from_queue
            , std::ref(queue)
            , std::ref(mtx)
            , i);

        ts.push_back(std::move(thread));
    }

    for (auto& t : ts) {
        t->join();
    }
    return 0;
}






