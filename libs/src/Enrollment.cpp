#include "../include/Enrollment.hpp"

Enrollment::Enrollment() {}

Enrollment::Enrollment(std::string code, std::string id, std::string acYear, ESemester semester) {
    this->code = code;
    this->id = id;
    this->acYear = acYear;
    this->semester = semester;
}

std::string Enrollment::getCode() {
    return this->code;
}

std::string Enrollment::getId() {
    return this->id;
}

std::string Enrollment::getAcYear() {
    return this->acYear;
}

std::string Enrollment::getSemester_str() {
    return smtToStr(this->semester);
}

ESemester Enrollment::getSemester_enum() {
    return this->semester;
}

std::ostream& operator<< (std::ostream &out, Enrollment &e) {
    out << e.code << (std::string) "|"
        << e.id   << (std::string) "|"
        << e.acYear    << (std::string) "|"
        << smtToStr(e.semester);
    return out;
}

bool Enrollment::operator== (Enrollment &other) const {
    return this->code   == other.code  &&
           this->id  == other.id &&
           this->acYear   == other.acYear  &&
           this->semester == other.semester;
}

bool Enrollment::operator< (Enrollment other) {
    auto v1 = std::stoi(this->acYear.substr(0,4));
    auto v2 = std::stoi(other.acYear.substr(0,4));
    if (v1 != v2)
        return v1 < v2;
    if (this->semester != other.semester)
        return this->semester < other.semester;
    if (this->code != other.code)
        return this->code < other.code;
    return this->id < other.id;
}

bool Enrollment::operator< (const Enrollment &other) const {
    auto v1 = std::stoi(this->acYear.substr(0,4));
    auto v2 = std::stoi(other.acYear.substr(0,4));
    if (v1 != v2)
        return v1 < v2;
    if (this->semester != other.semester)
        return this->semester < other.semester;
    if (this->code != other.code)
        return this->code < other.code;
    return this->id < other.id;
}

size_t Enrollment::EnrollmentHash::operator() (const Enrollment &__e) const {
    auto codeHash = std::hash<std::string>() (__e.code);
    auto idHash   = std::hash<std::string>() (__e.id);
    return (codeHash ^ idHash);
}