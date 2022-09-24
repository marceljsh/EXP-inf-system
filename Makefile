compile :
				g++ App.cpp ./libs/func/tools.cpp ./libs/src/Course.cpp ./libs/src/Enrollment.cpp ./libs/src/EProgram.cpp ./libs/src/ESemester.cpp ./libs/src/Simulator.cpp ./libs/src/Student.cpp -o App -Wno-deprecated

test_01 :
				./App