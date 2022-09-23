#include "../include/Student.hpp"

Student::Student() {
    this->credency.first  = "N/A";
    this->credency.second = "N/A";
    this->program         = EProgram::Prog_NA;
    this->year            = 0;
}

Student::Student(std::string id, std::string name) {
    this->credency.first  = id;
    this->credency.second = name;
    this->year            = Student::extractYear(id) + 2000;
    this->program         = strToProg(id.substr(0,3));
}

std::string Student::getId() {
    return this->credency.first;
}

std::string Student::getName() {
    return this->credency.second;
}

unsigned short Student::getAcYear() {
    return this->year;
}

EProgram Student::getProgram_enum() {
    return this->program;
}

std::string Student::getProgram_str() {
    return progToStr(this->program);
}

unsigned short Student::extractYear(std::string id) {
    return ((unsigned short) std::stoi(id.substr(3,2)));
}

std::ostream& operator<<( std::ostream& out, const Student& __s) {
    out << __s.credency.first
        << (std::string) "|"
        << __s.credency.second
        << (std::string) "|"
        << std::to_string(__s.year)
        << (std::string) "|"
        << progToStr(__s.program);
    return out;
}

bool Student::operator== (Student &other) const {
    return (this->credency.first == other.credency.first);
}

void Student::operator= (const Student &__s) {
    this->credency = __s.credency;
    this->program  = __s.program;
    this->year     = __s.year;
}

bool Student::operator< (Student other) {
    auto var1 = std::stoi(this->credency.first.substr(3,2));
    auto var2 = std::stoi(other.credency.first.substr(3,2));
    if (var1 != var2)
        return var1 < var2;
    if (this->program != other.program)
        return this->program < other.program;
    var1 = std::stoi(this->credency.first.substr(5,3));
    var2 = std::stoi(other.credency.first.substr(5,3));
    return var1 < var2;
}

bool Student::operator< (const Student &other) const {
    auto var1 = std::stoi(this->credency.first.substr(3,2));
    auto var2 = std::stoi(other.credency.first.substr(3,2));
    if (var1 != var2)
        return var1 < var2;
    if (this->program != other.program)
        return this->program < other.program;
    var1 = std::stoi(this->credency.first.substr(5,3));
    var2 = std::stoi(other.credency.first.substr(5,3));
    return var1 < var2;
}

// potential error
size_t Student::StudentHash::operator() (const Student &__s) const {
    return std::hash<std::string>() (__s.credency.first);
}