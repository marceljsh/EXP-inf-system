#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

template <typename Out> inline
void split(const std::string &s, char delim, Out result);

std::vector<std::string>
split_str_to_vec(const std::string &s, char delim);

void conslog();

// similar to print in Python
template <typename First, typename ... Printable>
void conslog(First arg, const Printable& ... rest) {
    std::cout << arg << " ";
    conslog(rest...);
}

#endif