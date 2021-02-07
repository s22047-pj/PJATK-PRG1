#include <fcntl.h>
#include <unistd.h>
#include <s22047/Student.h>
#include <iostream>
#include <sstream>


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
    auto student = s22047::Student{"Stanislaw", "Aniola", "s22047", 1, 0};
    std::cout << student.display_student();


    auto save_to_file = std::string{"./student.txt"};

    std::cout << "Saved to file: " << save_to_file << "\n";
    auto read_student_file = open(save_to_file.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);


    auto n = write(read_student_file, student.display_student().data(), student.display_student().size());

    if (n == -1) {
        perror("write(2)");
    }

    close(read_student_file);

    return 0;
}