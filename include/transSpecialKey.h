#pragma once
#include <iostream>

extern int specialKeyArray[8];
extern bool isSpecialKey;
extern std::string specialKeyString;

std::string translateSpecialKey(int vkCode);
