#include <thread>
#include <chrono>
#include <Windows.h>
#include "thread.h"
#include "function.h"

// This is a container or a wrapper for our function to run inside without being affected by the Sleep in each of it
void workerThread(void(*func)()) {
    while (true) {
        func();
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
}

void workerThreadClass(std::atomic<WeaponConfig*>& weapon, void (*func)(WeaponConfig&)) {
    while (true) {
        if (weapon.load() != nullptr) {
			func(*weapon.load());
		}
		
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
}
