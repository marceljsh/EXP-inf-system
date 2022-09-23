#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "Enrollment.hpp"
#include <iostream>
#include <list>
#include <set>

class Simulator {
    private:
        std::set<Course> courses;   // originally a list
        std::set<Student> students;
        std::set<Enrollment> enrollments;
    
    public:
        Simulator();
        bool hasCourse(std::string code);
        bool hasStudent(std::string id);
        bool hasEnrollment(Enrollment enrollment);
        bool add(Course course);
        bool add(Student student);
        bool add(Enrollment enrollment);
        bool enroll(std::string code, std::string id, std::string acYear, ESemester semester) throw (std::string);
        Course findCourse(std::string code) throw (std::string);
        Student findStudent(std::string id) throw (std::string);
        Enrollment findEnrollment(std::string code, std::string id) throw (std::string);
        friend std::ostream& operator<< (std::ostream &out, const Simulator &s);
};

#endif