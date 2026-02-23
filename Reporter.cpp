#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include "employee.h"

int main(int argc, char* argv[]) {
    if (argc < 4) return 1;

    char* binFile = argv[1];
    char* txtFile = argv[2];
    double rate = atof(argv[3]);

    std::ifstream in(binFile, std::ios::binary);
    std::ofstream out(txtFile);

    out << binFile << " report\n";
    out << "Number, name, hours, salary:\n";

    employee emp;
    
    while (in.read((char*)&emp, sizeof(employee))) {
        double salary = emp.hours * rate;
        out << emp.num << " " << emp.name << " " << emp.hours << " " << salary << "\n";
    }

    in.close();
    out.close();
    return 0;
}
