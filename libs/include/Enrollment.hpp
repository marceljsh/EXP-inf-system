#ifndef ENROLLMENT_HPP
#define ENROLLMENT_HPP

#include "Course.hpp"
#include "Student.hpp"
#include "ESemester.hpp"

class Enrollment {
    private:
        std::string code;
        std::string id;
        std::string acYear;     /* academic year */
        ESemester semester;
        Enrollment();           /* hide this constructor from the outside world. */
    
    public:
        Enrollment(std::string code, std::string id, std::string acYear, ESemester semester);
        std::string getCode();
        std::string getId();
        std::string getAcYear();
        std::string getSemester_str();
        ESemester getSemester_enum();
        friend std::ostream& operator<< (std::ostream &out, Enrollment &e);
        bool operator== (Enrollment &other) const;
        bool operator< (Enrollment other);
        bool operator< (const Enrollment &other) const;

        struct EnrollmentHash {
            size_t operator() (const Enrollment &__e) const;
        };
};

#endif