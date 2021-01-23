#ifndef S22047_STUDENT_H
#define S22047_STUDENT_H

#include <iostream>

namespace s22047 {
    struct Student {

        std::string const first_name;
        std::string const last_name;
        std::string const index;
        int semester;
        double avg_grade;

        Student(std::string, 
                std::string, 
                std::string, 
                int, 
                double);

        auto display_student() const -> std::string;
    };
} // namespace s22047

#endif