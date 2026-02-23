#define _MBCS
#undef UNICODE
#undef _UNICODE

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

struct employee {
    int num;
    char name[10];
    double hours;
};

void Start(std::string cmd) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    if (CreateProcess(
        NULL, 
        (char*)cmd.c_str(), 
        NULL, 
        NULL, 
        FALSE, 
        CREATE_NEW_CONSOLE, 
        NULL, 
        NULL, 
        &si, 
        &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}

int main() {
    std::string binFile, reportFile;
    int n; double rate;

    std::cout << "Bin file name: ";
    std::cin >> binFile;
    std::cout << "Number of records: ";
    std::cin >> n;
    Start("Creator.exe " + binFile + " " + std::to_string(n));
    binFile = binFile + ".bin";
    std::ifstream in(binFile, std::ios::binary);
    employee emp;
    while (in.read((char*)&emp, sizeof(employee))) 
        std::cout << emp.num << " " << emp.name << " " << emp.hours << "\n";
    in.close();

    std::cout << "Report file name: "; 
    std::cin >> reportFile;
    reportFile = reportFile + ".txt";
    std::cout << "Rate: "; 
    std::cin >> rate;
    Start("Reporter.exe " + binFile + " " + reportFile + " " + std::to_string(rate));

    std::ifstream rep(reportFile);
    std::string s;
    while (std::getline(rep, s)){
        std::cout << s << "\n";
    }
    return 0;
}
