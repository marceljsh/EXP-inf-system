# Instruction


## Overview

Pada program ini, ada 3 *class*, yaitu **Course**, **Student**, dan **Enrollment**.
Program akan menerima sebuah baris masukan dimana tiap segmen/elemen dalam masukan
dipisahkan dengan (```#```). Program akan terus menerima baris masukan sampai
program dihentikan dengan meng-input ("```---```") sebagai masukan. Setelah program
berhenti, terminal akan menampilkan detail dari setiap objek yang dibuat.

**Course** memiliki atribut:
1. ***std::pair*** ```credency``` dengan properti ***std::string*** ```.first``` = code dan ***std::string*** ```.second``` = name.
2. ***unsigned short*** ```credit``` artinya kredit atau sks.
3. ***std::string*** ```pGrade``` artinya passing grade.

**Student** memiliki atribut:
1. ***std::pair*** ```credency``` dengan properti ***std::string*** ```.first``` = id dan ***std::string*** ```.second``` = name.
2. ***unsigned short*** ```year``` artinya tahun angkatan.
3. ***EProgram*** ```program``` artinya program studi.



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
<3 digit prodi><2 digit angkatan><3 digit no. urut>

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

3. test-case 02
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

