#include "header.h"

int32_t countLines(const char* filename) {
    std::ifstream fin(filename);
    void CheckInputFIle(std::ifstream& file);

    int32_t count = 0;
    std::string line;
    while (std::getline(fin, line)){
        ++count;
    } 
    return count;
}

void loadStudentsFromFile(const char* filename, Student* students, int32_t size) {
    std::ifstream file(filename);
    void CheckInputFIle(std::ifstream& file);

    char buffer[100];
    int32_t index = 0;

    while (file.getline(buffer, sizeof(buffer)) && index < size) {
        char* name = strtok(buffer, ";");
        char* groupStr = strtok(nullptr, ";");
        char* gradeStr = strtok(nullptr, ";");

        if (!name || !groupStr || !gradeStr)
            throw std::runtime_error("u made a mistake in stirng in file");

        strncpy(students[index].name, name, sizeof(students[index].name));
        students[index].group = std::atoi(groupStr);
        students[index].grade = std::atof(gradeStr);
        ++index;
    }
}

void printStudents(const Student* students, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        std::cout << students[i].name;
        std::cout << "\tgroup is: " << students[i].group;
        std::cout << "\taverage of ball is: " << students[i].grade << '\n';
    }
}

void sortByName(Student* students, int32_t size) {
    for (int32_t i = 0; i < size - 1; ++i)
        for (int32_t j = i + 1; j < size; ++j)
            if (strcmp(students[i].name, students[j].name) > 0)
                std::swap(students[i], students[j]);
}

void sortByGroupAndName(Student* students, int32_t size) {
    for (int32_t i = 0; i < size - 1; ++i)
        for (int32_t j = i + 1; j < size; ++j)
            if (students[i].group > students[j].group ||
                (students[i].group == students[j].group &&
                 strcmp(students[i].name, students[j].name) > 0))
                std::swap(students[i], students[j]);
}

int32_t findBySurname( Student* students, int32_t size, const char* surname) {
    for (int32_t i = 0; i < size; ++i) {
        if (std::strstr(students[i].name, surname) == students[i].name) {
            return i;
        }
    }
    return -1;
}

void printAverageByGroup(Student* students, int32_t size) {
    int32_t max {100};
    double total[max] = {};
    int32_t count[max] = {};

    for (int32_t i = 0; i < size; ++i) {
        int32_t g = students[i].group;
        if (g >= 0 && g < max) {
            total[g] += students[i].grade;
            ++count[g];
        }
    }

    for (int32_t g = 0; g < max; ++g) {
        if (count[g] > 0) {
            std::cout << "Группа " << g << ": средний балл = "
                      << total[g] / count[g] << "\n";
        }
    }
}

void CheckInputFIle(std::ifstream& fin) {

	if (!fin.good()) {
		throw "file doesnt exist";
	}
	if (!fin) {
		throw "input file error";
	}
	if (fin.peek() == EOF) {
		throw "this file is empty";
    }
}
