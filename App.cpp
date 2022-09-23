#include "./libs/include/Student.hpp"
#include "./libs/include/Course.hpp"
#include "./libs/include/Enrollment.hpp"
#include "./libs/include/Simulator.hpp"     //TODO: coba gabung semua artefak di satu namespace
#include "./libs/func/tools.hpp"

#define __DELIM__ '#'
#define __STOP__ "---"

int main(int _argc, char* _argv[])
{
    Simulator simulator = Simulator();
    std::vector<std::string> data;
    std::string bucket;

    while (true) {
        std::getline(std::cin, bucket);
        if (bucket == __STOP__)
            break;
        data = split_str_to_vec(bucket, __DELIM__);

        // ADDING COURSE
        if (data.at(0) == "course-add")
            simulator.add(Course(data.at(1),
                                 data.at(2),
                                 (unsigned short) std::stoi(data.at(3)),
                                 data.at(4)));

        // ADDING STUDENT
        else if (data.at(0) == "student-add")
            simulator.add(Student(data.at(1), data.at(2)));

        // ADDING ENROLLMENT
        else if (data.at(0) == "enrollment-add")
            simulator.enroll(data.at(1),
                             data.at(2),
                             data.at(3),
                             strToSmt(data.at(4)));
        
        // DISPLAY TARGET STUDENT
        else if (data.at(0) == "find-student")
            conslog(simulator.findStudent(data.at(1)));
        
        // DISPLAY TARGET COURSE
        else if (data.at(0) == "find-course")
            conslog(simulator.findCourse(data.at(1)));
        
        // DISPLAY TARGET ENROLLMENT
        else if (data.at(0) == "find-enrollment")
            conslog(simulator.findEnrollment(data.at(1), data.at(2)));
    }

    conslog(simulator);

    return EXIT_SUCCESS;
}