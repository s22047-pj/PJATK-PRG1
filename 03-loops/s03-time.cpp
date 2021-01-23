#include <s22047/Time.h>
#include <iostream>
#include <sstream>
#include <string>

s22047::Time::Time(int hh, 
                    int mm,
                    int ss)
        : hh{hh},
        mm{mm},
        ss{ss}
{}

auto s22047::Time::to_string(const Time_of_day time_of_day) -> std::string
{
    switch (time_of_day) {
    case Time_of_day::morning:
        return "Morning\n";
    case Time_of_day::day:
        return "Day\n";
    case Time_of_day::evening:
        return "Evening\n";
    default: //Time_of_day::night:
        return "Night\n";
    }
}


auto s22047::Time::time_of_day() const -> Time::Time_of_day
{
    if (hh <= 6) {
        return Time_of_day::night;
    } else if (hh <= 10) {
        return Time_of_day::morning;
    } else if (hh <= 17) {
        return Time_of_day::day;
    } else if (hh <= 21) {
        return Time_of_day::evening;
    } else {
        return Time_of_day::night;
    }
}




auto s22047::Time::operator<(Time const& time) -> bool
{
    if (hh == time.hh and mm == time.mm){
        return ss < time.ss;
    }
    if (hh == time.hh){
        return mm < time.mm;
    }

    return ss < time.ss;
}

auto s22047::Time::operator>(Time const& time) -> bool
{
    if (hh == time.hh and mm == time.mm){
        return ss > time.ss;
    }
    if (hh == time.hh){
        return mm > time.mm;
    }

    return ss > time.ss;
}




auto s22047::Time::time_to_midnight() const -> Time
{
    auto time_to_midnight = Time{0, 0, 0} - *this;
    return time_to_midnight;
}

auto s22047::Time::to_string() const -> std::string
{
    auto out = std::ostringstream{};

    std::string add_zero_hh = std::to_string(hh);
    if (std::to_string(hh).length()==1){
        add_zero_hh = "0" + std::to_string(hh);
    }

    auto add_zero_mm = std::to_string(mm);
    if (std::to_string(mm).length()==1){
        add_zero_mm = "0" + std::to_string(mm);
    }

    auto add_zero_ss = std::to_string(ss);
    if (std::to_string(ss).length()==1){
        add_zero_ss = "0" + std::to_string(ss);
    }

    out << add_zero_hh << ""
        << ":" << add_zero_mm << ""
        << ":" << add_zero_ss << "\n";

    return out.str();
}

auto s22047::Time::next_hour()
{
    hh=hh+1;
    if(hh>23){
        hh=0;
    }
}

auto s22047::Time::next_minute()
{
    mm=mm+1;
    if(mm>59){
        mm=0;
        next_hour();
    }
}

auto s22047::Time::next_second()
{
    ss=ss+1;
    if(ss>59){
        ss=0;
        next_minute();
    }
}

auto s22047::Time::operator+(Time const& time) -> Time
{
    for (int i = 0; i < time.hh; i++)
    {
        next_hour();
    }

    for (int i = 0; i < time.mm; i++)
    {
        next_minute();
    }
    
    for (int i = 0; i < time.ss; i++)
    {
        next_second();
    }
    
    return *this;
}

auto s22047::Time::operator-(Time const& time) -> Time
{
    auto hh_stamp = hh - time.hh;
    auto mm_stamp = mm - time.mm;
    auto ss_stamp = ss - time.ss;

    if (hh_stamp < 0){
        hh = 24 + hh_stamp;
    }
    if (mm_stamp < 0){
        hh_stamp = hh_stamp - 1;
        mm = 60 + mm_stamp;        
    }
    if (ss_stamp < 0){
        mm_stamp = mm_stamp - 1;
        ss = 60 + ss_stamp;
    }

    return *this;
}

auto s22047::Time::operator==(Time const& time) -> bool
{
    return (hh == time.hh and mm == time.mm and ss == time.ss);
}

auto s22047::Time::operator!=(Time const& time) -> bool
{
    return (hh != time.hh and mm != time.mm and ss != time.ss);
}

auto s22047::Time::count_seconds() const -> uint64_t
{
    auto time_in_seconds = ss + mm*60 + hh*3600;
    return time_in_seconds;
}

auto s22047::Time::count_minutes() const -> uint64_t
{
    auto time_in_minutes = ss/60 + mm + hh*60;
    return time_in_minutes;
} 

auto main() -> int
{
    std::cout << "Time::to_string(): " << "\n";
    s22047::Time time = s22047::Time{ 23, 59, 59 };
    std::cout << time.to_string() << "\n";

    std::cout << "Time::next_hour(): " << "\n";
    time = s22047::Time{ 23, 59, 59 };
    time.next_hour();
    std::cout << time.to_string() << "\n";

    std::cout << "Time::next_minute()" << "\n";
    time = s22047::Time{ 23, 59, 59 };
    time.next_minute();
    std::cout << time.to_string() << "\n";

    std::cout << "Time::next_second()" << "\n";
    time = s22047::Time{ 23, 59, 59 };
    time.next_hour();
    std::cout << time.to_string() << "\n";

    std::cout << "Time::time_of_day()" << "\n";
    time = s22047::Time{ 23, 59, 59 };
    std::cout << s22047::Time::to_string(time.time_of_day()) << "\n";

    std::cout << "Time::operator+()" << "\n";
    auto a = s22047::Time{ 23, 59, 59 };
    auto b = s22047::Time{  0,  0,  1 };
    std::cout << (a + b).to_string() << "\n";

    std::cout << "Time::operator-()" << "\n";
    a = s22047::Time{  3, 59, 59 };
    b = s22047::Time{  4,  0,  0 };
    std::cout << (a - b).to_string() << "\n";

    std::cout << "Time::operator<()" << "\n";
    a = s22047::Time{ 23, 59, 59 };
    b = s22047::Time{  0,  0,  1 };
    if (a > b) {
        std::cout << a.to_string() << " > " << b.to_string() << "\n";
    } else {
        std::cout << a.to_string() << " ? " << b.to_string() << "\n";
    }

    std::cout << "Time::operator==()" << "\n";
    a = s22047::Time{ 23, 59, 59 };
    b = s22047::Time{  0,  0,  1 };
    if (a == b) {
        std::cout << a.to_string() << " == " << b.to_string() << "\n";
    } else {
        std::cout << a.to_string() << " != " << b.to_string() << "\n";
    }

    std::cout << "Time::count_seconds()" << "\n";
    time = s22047::Time{ 23, 59, 59 };
    std::cout << time.count_seconds() << "\n";

    std::cout << "Time::count_minutes()" << "\n";
    time = s22047::Time{ 23, 59, 59 };
    std::cout << time.count_minutes() << "\n";

    std::cout << "Time::time_to_midnight()" << "\n";
    time = s22047::Time{ 23, 59, 59 };
    std::cout << time.time_to_midnight().to_string() << "\n";

    return 0;
}




