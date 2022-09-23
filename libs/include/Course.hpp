#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

class Course {
    private:
        std::pair<std::string, std::string> credency;
        unsigned short credit;
        std::string pGrade;

    public:
        Course();
        Course(std::string code, std::string name, unsigned short credit, std::string pGrade);
        std::string getCode();
        std::string getName();
        unsigned short getCredit();
        std::string getPGrade();
        friend std::ostream& operator << (std::ostream& out, const Course& __c);
        bool operator== (Course &other) const;
        bool operator!= (Course other);
        bool operator!= (const Course &other) const;
        void operator= (const Course &__c);
        bool operator< (Course other);
        bool operator< (const Course &other) const;

        struct CourseHash {
            size_t operator() (const Course &__c) const;
        };
};

#endif