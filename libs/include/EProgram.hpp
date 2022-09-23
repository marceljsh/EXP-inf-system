#ifndef EPROGRAM_HPP
#define EPROGRAM_HPP

#include <string>

typedef enum {
    Prog_NA, SI, IF, TE, MR, TB, TRPL, TI, TK
} EProgram;

std::string progToStr(EProgram _program);
EProgram strToProg(std::string _program);

#endif