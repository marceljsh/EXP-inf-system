# [EXP]-inf-system

## `Overview 🏝`
This project is the `C++` version of my [_OOP Course Project_](https://github.com/marceljsh/COURSE-object-oriented). This project emphasizes OOP concept using `C++` and will add new features from previous versions during development.

In this program, there are 3 *classes*, namely **Course**, **Student**, and **Enrollment**. The program will receive an input line where each segment/element in the input separated by (```#```). The program will continue to receive input lines until the program is terminated by inputting ("```---```") as input. After program stops, the terminal will display the details of each object created.

**Course** has attributes:
1. ***std::pair*** ```credency``` with property ***std::string*** ```.first``` = code and ***std::string* ** ```.second``` = name.
2. ***unsigned short*** ```credit``` means credit.
3. ***std::string*** ```pGrade``` means passing grade.

**Student** has attributes:
1. ***std::pair*** ```credency``` with property ***std::string*** ```.first``` = id and ***std::string* ** ```.second``` = name.
2. ***unsigned short*** ```year``` means entrance year.
3. ***EProgram*** ```program``` means student's study program.

## Input Format

1. adding Course
```bash
course-add#<code>#<name>#<credit>#<passing grade>
```

2. adding Student
```bash
student-add#<id>#<name>
```

3. adding Enrollment
```bash
enrollment-add#<course_code>#<student_id>#<academic_year>#<semester>
```

4. format ID (NIM)
```bash
<3 digit progm><2 digit ent year><3 digit serialnum>

       12S              20               003    --> 12S20003
```


## Compile Command
```bash
g++ -Wno-deprecated App.cpp ./libs/func/tools.cpp ./libs/src/Course.cpp ./libs/src/Enrollment.cpp ./libs/src/EProgram.cpp ./libs/src/ESemester.cpp ./libs/src/Simulator.cpp ./libs/src/Student.cpp -o App
```



## I/O Example

1. test-case 01
**input:**
```bash
course-add#12S1101#Pemrograman Prosedural#3#C
student-add#21S18025#Vino Susanto
student-add#21S18026#Vina Susanti
enrollment-add#12S1101#21S18025#2022/2023#EVEN
enrollment-add#12S1101#21S18026#2022/2023#EVEN
---

```

**output:**
```bash
12S1101|Pemrograman Prosedural|3|C
21S18025|Vino Susanto|2018|Engineering Management
21S18026|Vina Susanti|2018|Engineering Management
12S1101|21S18025|2022/2023|EVEN
12S1101|21S18026|2022/2023|EVEN

```

2. test-case 02
**input:**
```bash
course-add#12S1101#Pemrograman Prosedural#3#C
student-add#12S14001#John Doe
student-add#12S14002#Jane Doe
student-add#11S14001#Putra Laksawan
student-add#11S14002#Putri Laksawati
enrollment-add#12S1101#12S14001#2022/2023#EVEN
enrollment-add#12S1101#12S14002#2022/2023#EVEN
enrollment-add#12S1101#11S14001#2022/2023#EVEN
enrollment-add#12S1103#11S14002#2022/2023#EVEN
enrollment-add#12S1101#11S14002#2022/2023#EVEN
---

```

**output:**
```bash
course with CODE: <12S1103> not found
invalid course|12S1103
12S1101|Pemrograman Prosedural|3|C
12S14001|John Doe|2014|Information System
12S14002|Jane Doe|2014|Information System
11S14001|Putra Laksawan|2014|Informatics
11S14002|Putri Laksawati|2014|Informatics
12S1101|12S14001|2022/2023|EVEN
12S1101|12S14002|2022/2023|EVEN
12S1101|11S14001|2022/2023|EVEN
12S1101|11S14002|2022/2023|EVEN

```

## `License📜`
Copyright © 2022, Marcel Joshua. Released under [Information Systems](https://www.del.ac.id/?page_id=3534), FITE, [Del Institute of Technology](https://www.del.ac.id/)
***
_This property is intended as a personal exploration project_
