#include <fcntl.h>
#include <unistd.h>
#include <s22047/Student.h>
#include <iostream>
#include <sstream>
#include <fstream>


s22047::Student::Student(std::string first_name,
                         std::string last_name,
                         std::string index,
                         int semester,
                         double avg_grade)
        : first_name{first_name}
        , last_name{last_name}
        , index{index}
        , semester{semester}
        , avg_grade{avg_grade}
{}

auto s22047::Student::display_student() const -> std::string
{
    auto out = std::ostringstream{};
    out << "First name: " << first_name << "\n"
        << "Last name: " << last_name << "\n"
        << "Index number: " << index << "\n"
        << "Semester: " << semester << "\n"
        << "Notes average: " << avg_grade << "\n";

    return out.str();
}

auto main() -> int
{


    auto student_file = std::string{"./student.txt"};
    auto read_from_file = std::ifstream{};
    read_from_file.open(student_file);

    if (!read_from_file)
    {
        std::cerr << "Cannot open a file" << std::endl;
        return 1;
    }
    
    auto c = char{};
    while (read_from_file.get(c))
    {
        std::cout << c;
    }
    std::cout << std::endl;
    read_from_file.close();


    return 0;
}