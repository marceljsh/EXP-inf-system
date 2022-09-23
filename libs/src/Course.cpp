#include "../include/Course.hpp"

Course::Course() {
    this->credency.first = "N/A";
    this->credency.second = "N/A";
    this->credit = 0;
    this->pGrade = "N/A";
}

Course::Course(std::string code, std::string name, unsigned short credit, std::string pGrade) {
    this->credency.first = code;
    this->credency.second = name;
    this->credit = credit;
    this->pGrade = pGrade;
}

std::string Course::getCode() {
    return this->credency.first;
}

std::string Course::getName() {
    return this->credency.second;
}

unsigned short Course::getCredit() {
    return this->credit;
}

std::string Course::getPGrade() {
    return this->pGrade;
}

std::ostream& operator << (std::ostream& out, const Course& __c) {
    out << __c.credency.first         << (std::string) "|"
        << __c.credency.second        << (std::string) "|"
        << std::to_string(__c.credit) << (std::string) "|"
        << __c.pGrade;
    return out;
}

bool Course::operator== (Course &other) const {
    return this->credency.first == other.credency.first;
}

bool Course::operator!= (Course other){
    return this->credency.first != other.credency.first;
}

bool Course::operator!= (const Course &other) const {
    return this->credency.first != other.credency.first;
}

void Course::operator= (const Course &__c) {
    this->credency = __c.credency;
    this->credit = __c.credit;
    this->pGrade = __c.pGrade;
}

bool Course::operator< (Course other) {
    auto v1 = std::stoi(this->credency.first.substr(3,4));
    auto v2 = std::stoi(other.credency.first.substr(3,4));
    return v1 < v2;
}

bool Course::operator< (const Course &other) const {
    auto v1 = std::stoi(this->credency.first.substr(3,4));
    auto v2 = std::stoi(other.credency.first.substr(3,4));
    return v1 < v2;
}

size_t Course::CourseHash::operator() (const Course &__c) const {
    return std::hash<std::string>() (__c.credency.first);
}