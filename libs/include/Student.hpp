#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "EProgram.hpp"
#include <string>

class Student {
    protected:
        std::pair <std::string, std::string> credency;
        unsigned short year;
        EProgram program;

        unsigned short extractYear(std::string id);
    
    public:
        Student();
        Student(std::string id, std::string name);
        std::string getId();
        std::string getName();
        unsigned short getAcYear();
        EProgram getProgram_enum();
        std::string getProgram_str();
        friend std::ostream& operator << (std::ostream& out, const Student& __s);
        bool operator== (Student &other) const;
        void operator= (const Student &__s);
        bool operator< (Student other);
        bool operator< (const Student &other) const;
        
        // potential error
        struct StudentHash {
            size_t operator() (const Student &__s) const;
        };
};

#endif