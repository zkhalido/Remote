#include <iostream>
#include <windows.h>

int specialKeyArray[] = {VK_SPACE, VK_RETURN, VK_BACK, VK_CAPITAL, VK_SHIFT, VK_TAB, VK_CONTROL, VK_MENU};

bool isSpecialKey;
std::string specialKeyString;

std::string translateSpecialKey(int vkCode){
    std::string result;

    std::cout << "translateSpecialKey : " << vkCode << std::endl;

    switch(vkCode){
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