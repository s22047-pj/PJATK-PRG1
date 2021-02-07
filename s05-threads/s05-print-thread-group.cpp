#include <iostream>
#include <thread>

auto display_thread(int group_i, int thread_i) -> void
{
    std::cout << "group: " << group_i << ", thread: " << thread_i << std::endl;
}

auto get_from_group(int group_i) -> void
{
    for (auto thread_i = 0; thread_i < 7; ++thread_i) {
        auto a_thread = std::thread(display_thread, group_i, thread_i);
        a_thread.detach();
    }
}   

auto main() -> int
{
    for (auto group_i = 0; group_i < 8; ++group_i) {
        auto a_thread = std::thread(get_from_group, group_i);
        a_thread.join();
    }
    return 0;
} 

/*
auto loop_thread(std::string thr_gr, int count, void* func_lp) -> void
{
    for (auto thr_gr_i = 0; thr_gr_i < count; ++thr_gr_i) {
        auto a_thr_gr = std::thread(func_lp, thr_gr_i);

        if (thr_gr == "thread"){
            a_thr_gr.join();
        } else if (thr_gr == "group"){
            a_thr_gr.detach();
        }
    }
}
*/