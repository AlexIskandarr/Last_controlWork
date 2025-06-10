#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdint>

struct Student {
    char name[30];
    int group;
    double grade;
};

int32_t countLines(const char* filename);
void loadStudentsFromFile(const char* filename, Student* students, int32_t size);
void printStudents(const Student* students, int32_t size);
void sortByName(Student* students, int32_t size);
void sortByGroupAndName(Student* students, int32_t size);
int32_t findBySurname( Student* students, int32_t size, const char* surname);
void printAverageByGroup( Student* students, int32_t size);
