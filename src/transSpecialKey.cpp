#include <iostream>
#include <windows.h>

int specialKeyArray[] = {VK_SPACE, VK_RETURN, VK_BACK, VK_CAPITAL, VK_SHIFT, VK_TAB, VK_CONTROL, VK_MENU};
//int specialKeyArray[] = {VK_SPACE, VK_RETURN, VK_BACK};

bool isSpecialKey;
std::string specialKeyChar;

std::string translateSpecialKey(int key){
    std::string result;

    switch(key){
    case VK_SPACE:
        result = " ";
        break;
    case VK_RETURN:
        result = "\n";
        break;
    case VK_BACK:
        result = "\b";
        break;
    case VK_CAPITAL:
       result = "[CAPS_LOCK]";
        break;
    case VK_SHIFT:
       result = "[SHIFT]";
        break;
    case VK_TAB:
        result = "[TAB]";
        break;
    case VK_CONTROL:
        result = "[CTRL]";
        break;
    case VK_MENU:
        result = "[ALT]";
        break;
    default:
        break;
    
    }

    return result;
}