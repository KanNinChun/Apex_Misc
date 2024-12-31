#include <windows.h>
#include <iostream>
#include <vector>
#include "weapon.h"
#include"asyncMouse.h"
#include <thread>
#include "function.h"

// Function to simulate relative mouse movement
void MoveMouseRelative(int x, int y, WeaponConfig& weapon) {
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;
    input.mi.dx = x / weapon.x;
    input.mi.dy = y / weapon.y;
    SendInput(1, &input, sizeof(input));
    Sleep(weapon.moveSleep);
    SendInput(1, &input, sizeof(input));
    Sleep(weapon.moveSleep);
    SendInput(1, &input, sizeof(input));
    Sleep(weapon.moveSleep);
}

// Function to handle mouse movement according to weapon's pattern
void weaponmove(WeaponConfig& weapon) {
    if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_RBUTTON)) {
        if (weapon.shotsFired <= weapon.maxShots) {
            MoveMouseRelative(weapon.patternX[weapon.shotsFired], weapon.patternY[weapon.shotsFired], weapon);
            Sleep(weapon.sleep);
            weapon.shotsFired++;
        }
    }
    else {
        weapon.shotsFired = 0;
    }
}

void superglide() 
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.wVk = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    ip.ki.wScan = MapVirtualKey(VK_SPACE, MAPVK_VK_TO_VSC); // Scan for Space KEY

    // Press Space key
    SendInput(1, &ip, sizeof(INPUT));
    // Release Space key
    ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

	ZeroMemory(&ip, sizeof(INPUT));

    auto sleeptme = std::chrono::microseconds(706);
    std::this_thread::sleep_for(sleeptme);

    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.wVk = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    ip.ki.wScan = MapVirtualKey(VK_CONTROL, MAPVK_VK_TO_VSC); // Scan for CTRL KEY
    SendInput(1, &ip, sizeof(INPUT));
    // Release Ctrl key
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    ZeroMemory(&ip, sizeof(INPUT));
    // Sleep for 500 milliseconds (half a second) 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void checkMouseWheel() {
    while (true)
    {
        if (GetScrollDelta() == -1)
        {
            superglide();
        }
    }
}


// Function to perform the fast loot action while holding XButton1
void fastLoot()
{
    while (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) {

        INPUT ip;
        ZeroMemory(&ip, sizeof(INPUT));
        ip.type = INPUT_KEYBOARD;
        ip.ki.time = 0;
        ip.ki.wVk = 0x45;
        ip.ki.dwExtraInfo = 0;
        ip.ki.dwFlags = KEYEVENTF_SCANCODE;
        ip.ki.wScan = MapVirtualKey(0x45, MAPVK_VK_TO_VSC); // Scan for Space KEY
        // Press E key
        SendInput(1, &ip, sizeof(INPUT));
        // Release E key
        ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        

        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Adjust the delay as needed
    }
}
