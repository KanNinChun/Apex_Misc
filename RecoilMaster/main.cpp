#include <windows.h>
#include <iostream>
#include <vector>
#include "weapon.h"
#include "function.h"
#include "thread.h"
#include <thread>
#include "menu.h"

int main() {

    menu();

	std::thread Thread_class(workerThread, switchWeapon);
	std::thread Thread_move(workerThreadClass, std::ref(currentWeapon), weaponmove);
	std::thread Thread_superglide(workerThread, checkMouseWheel);
	std::thread Thread_fastLoot(workerThread, fastLoot);

    // Detach the threads to allow them to run independently
    Thread_class.detach();
    Thread_move.detach();
    Thread_superglide.detach();
    Thread_fastLoot.detach();

    // Main loop to monitor for the stop signal
    while (!(GetAsyncKeyState(VK_INSERT) & 0x8000)) {

        Sleep(100); // Adjust as needed
    }

    std::cout << "Script stopped." << std::endl;
    return 0;
}
