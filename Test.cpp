#include "./libs/include/Student.hpp"
#include "./libs/include/Course.hpp"
#include "./libs/include/Enrollment.hpp"
#include "./libs/include/Simulator.hpp"     //TODO: coba gabung semua artefak di satu namespace
#include "./libs/func/tools.hpp"

int main(int _argc, char *_argv[])
{
  auto v1 = Student("12S20003","Marcel Joshua");
  auto v2 = Course("12S1101","Basis Data",4,"C");

  return EXIT_SUCCESS;
}