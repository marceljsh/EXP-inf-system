#include "../include/Simulator.hpp"

#define NULL_COURSE (Course)(Course("N/A","N/A",0,"N/A"))
#define NULL_STUDENT (Student)(Student("N/A","N/A"))
#define NULL_ENR (Enrollment)(Enrollment("N/A","N/A","N/A",ESemester::Smt_NA))

Simulator::Simulator() {
    /* do nothing */
}

bool Simulator::hasCourse(std::string code) {
    for (auto obj: this->courses)
        if (obj.getCode() == code )
            return true;
    return false;
}

bool Simulator::hasStudent(std::string id) {
    for (auto obj: this->students)
        if (obj.getId() == id)
            return true;
    return false;
}

bool Simulator::hasEnrollment(Enrollment enrollment) {
    for (auto obj: this->enrollments)
        if (obj.getCode() == enrollment.getCode() && obj.getId() == enrollment.getId())
            return true;
    return false;
}

bool Simulator::add(Course course) {
    if (hasCourse(course.getCode()))
        return false;
    this->courses.insert(course);
    return true;
}

bool Simulator::add(Student student) {
    if (hasStudent(student.getId()))
        return false;
    this->students.insert(student);
    return true;
}

bool Simulator::add(Enrollment enrollment) {
    if (hasEnrollment(enrollment))
        return false;
    this->enrollments.insert(enrollment);
    return true;
}

bool Simulator::enroll(std::string code, std::string id, std::string acYear, ESemester semester)
throw(std::string) {
    try {
        if (!hasCourse(code))
            throw ("invalid course|" + code);
        else {
            if (!hasStudent(id))
                throw ("invalid student|" + id);
            else {
                Enrollment newEnrollment = Enrollment(code, id, acYear, semester);
                return this->add(newEnrollment);
            }
        }
    }

    catch (std::string message) {
        std::cout << message << std::endl;
    }
    return false;
}

Course Simulator::findCourse(std::string code) throw (std::string) {
    try {
        for (auto obj: this->courses)
            if (obj.getCode() == code)
                return obj;
        throw ("course with CODE: <" + code + "> not found");
    }
    catch (std::string message) {
        std::cout << message << std::endl;
    }
    return NULL_COURSE;
}

Student Simulator::findStudent(std::string id) throw (std::string) {
    try {
        for (auto obj: this->students)
            if (obj.getId() == id)
                return obj;
        throw ("student with ID: <" + id + "> not found");
    }
    catch (std::string message) {
        std::cout << message << std::endl;
    }
    return NULL_STUDENT;
}

Enrollment Simulator::findEnrollment(std::string code, std::string id) throw (std::string) {
    try {
        for (auto obj: this->enrollments)
            if (obj.getCode() == code && obj.getId() == id)
                return obj;
        throw ("enrollment with CODE: <" + code + "> and ID: <" + id + "> not found");
    }
    catch (std::string message) {
        std::cout << message << std::endl;
    }
    return NULL_ENR;
}

std::ostream& operator<< (std::ostream &out, const Simulator &s) {
    for (auto obj: s.courses)
        out << obj << "\n";
    for (auto obj: s.students)
        out << obj << "\n";
    for (auto obj: s.enrollments)
        out << obj << "\n";
    return out;
}
