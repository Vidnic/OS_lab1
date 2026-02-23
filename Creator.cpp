#include <iostream>
#include <fstream>
#include <windows.h>
#include "employee.h"

int main(int argc, char* argv[]) {
    if (argc < 3) return 1;

    char* filename = argv[1];
    int n = atoi(argv[2]);

    std::ofstream out(filename, std::ios::binary);
    
    for (int i = 0; i < n; ++i) {
        employee emp;
        std::cout << "Input ID, name, hours for employee" << i + 1 << ": ";
        std::cin >> emp.num >> emp.name >> emp.hours;
        out.write((char*)&emp, sizeof(employee));
    }
    out.close();
    return 0;
}