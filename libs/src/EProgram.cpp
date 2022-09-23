#include "../include/EProgram.hpp"

std::string progToStr(EProgram _program) {
    switch (_program) {
        case EProgram::SI   : return "Information System";
        
        case EProgram::IF   : return "Informatics";
        
        case EProgram::TE   : return "Electrical Engineering";

        case EProgram::MR   : return "Engineering Management";
        
        case EProgram::TB   : return "Bioprocess Engineering";
        
        case EProgram::TRPL : return "Software Engineering";
        
        case EProgram::TI   : return "Information Technology";
        
        case EProgram::TK   : return "Computer Engineering";
        
        default:
            return "N/A"; break;
    }
}

EProgram strToProg(std::string _program) {
    if (_program == "Information System" || _program == "12S")
        return EProgram::SI;
    else if (_program == "Informatics" || _program == "11S")
        return EProgram::IF;
    else if (_program == "Electrical Engineering" || _program == "14S")
        return EProgram::TE;
    else if (_program == "Engineering Management" || _program == "21S")
        return EProgram::MR;
    else if (_program == "Bioprocess Engineering" || _program == "31S")
        return EProgram::TB;
    else if (_program == "Software Engineering" || _program == "114")
        return EProgram::TRPL;
    else if (_program == "Information Technology" || _program == "113")
        return EProgram::TI;
    else if (_program == "Computer Engineering" || _program == "133")
        return EProgram::TK;
    else return EProgram::Prog_NA;
}
