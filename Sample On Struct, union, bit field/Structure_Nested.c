//
// Author: Saifur Rahman
// Last Modified: 25 NOV 2020
//

#include <stdio.h>
#include <string.h>

typedef struct {
    int roll;
    char name[6];
    double gpa;
} Student;

typedef struct {
    Student std[50];
    int nStudents;
    char teacher[25+1];
} Class;

void printStudent(Student std) {
    printf("%s %d %f\n", std.name, std.roll, std.gpa);
}

void printClass(Class cls) {
    int i;
    printf("Teacher: %s\n", cls.teacher);
    printf("No. of students: %d\n", cls.nStudents);
    for (i = 0; i < cls.nStudents; i++)
        printStudent(cls.std[i]);
}

void readStudent(Student *pStd) {
    scanf("%s%d%lf", pStd->name, &pStd->roll, &pStd->gpa);
}

int main()
{
    Class cls;
    int i;

    cls.nStudents = 2;
    strcpy(cls.teacher, "Saifur");
    for (i = 0; i < cls.nStudents; i++) {
        readStudent(&cls.std[i]);
    }

    printClass(cls);

    return 0;
}
