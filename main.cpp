#include "header.h"
#include <iostream>

int main() {
    const char* filename = "students.txt";
    Student* students = nullptr;
    int32_t size {};

    try {
        size = countLines(filename);
        students = new Student[size];
        loadStudentsFromFile(filename, students, size);
    } catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << "\n";
        return 1;
    }

    int32_t choice {};
    do {
        std::cout << "\n menu:\n";
        std::cout << "1. sort by surname\n";
        std::cout << "2. find by surname\n";
        std::cout << "3. sort by group and surname\n";
        std::cout << "4. average by group\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    sortByName(students, size);
                    printStudents(students, size);
                    break;
                case 2: {
                    char surname[30];
                    std::cout << "enter surname: ";
                    std::cin >> surname;
                    int32_t index = findBySurname(students, size, surname);
                    if (index >= 0){
                        std::cout << "Найден: " << students[index].name;
                        std::cout << " group " << students[index].group;
                        std::cout << " ball " << students[index].grade;
                    }
                    else
                        std::cout << "Student undefinde.\n";
                    break;
                }
                case 3:
                    sortByGroupAndName(students, size);
                    printStudents(students, size);
                    break;
                case 4:
                    printAverageByGroup(students, size);
                    break;
                case 0:
                    std::cout << "exit.\n";
                    break;
                default:
                    std::cout << "mistake in choise.\n";
            }
        } catch (const std::exception& ex) {
            std::cerr << "error: " << ex.what() << "\n";
        }
    } while (choice != 0);

    delete[] students;
    return 0;
}
