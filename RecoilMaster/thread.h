#pragma once
#include "weapon.h"

void workerThread(void(*func)());
void workerThreadClass(std::atomic<WeaponConfig*>& weapon, void (*func)(WeaponConfig&));
