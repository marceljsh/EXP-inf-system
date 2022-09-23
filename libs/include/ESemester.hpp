#ifndef ESEMESTER_HPP
#define ESEMESTER_HPP

#include <string>

typedef enum {
    Smt_NA, ODD, EVEN, SHORT
} ESemester;

std::string smtToStr(ESemester _program);
ESemester strToSmt(std::string _program);

#endif