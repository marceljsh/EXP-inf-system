#include "../include/ESemester.hpp"

std::string smtToStr(ESemester _program) {
    switch (_program) {
        case ESemester::ODD   : return "odd"; break;
        
        case ESemester::EVEN  : return "even"; break;
        
        case ESemester::SHORT : return "short"; break;
        
        default:
            return "N/A"; break;
    }
}

ESemester strToSmt(std::string _program) {
    if (_program == "ODD" || _program == "odd")
        return ESemester::ODD;
    else if (_program == "EVEN" || _program == "even")
        return ESemester::EVEN;
    else if (_program == "SHORT" || _program == "short")
        return ESemester::SHORT;
    else return ESemester::Smt_NA;
}