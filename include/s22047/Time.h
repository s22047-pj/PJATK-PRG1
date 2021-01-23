#ifndef S22047_TIME_H
#define S22047_TIME_H

#include <iostream>

namespace s22047 {
    struct Time {

        int hh;
        int mm;
        int ss;

        Time(int, 
            int, 
            int);       

        enum class Time_of_day {morning, day, evening, night};
        static auto to_string(Time_of_day const) -> std::string;
        auto time_of_day() const -> Time_of_day;
        
        auto to_string() const -> std::string;

        auto next_hour();
        auto next_minute();
        auto next_second();

        auto operator+(Time const&) -> Time;
        auto operator-(Time const&) -> Time;
        auto operator<(Time const&) -> bool;
        auto operator>(Time const&) -> bool;
        auto operator==(Time const&) -> bool;
        auto operator!=(Time const&) -> bool;

        auto count_seconds() const -> uint64_t;
        auto count_minutes() const -> uint64_t;
        auto time_to_midnight() const -> Time;

    };
} // namespace s22047

#endif