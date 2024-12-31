#pragma once
#include "weapon.h"
#include <Windows.h>

// Function to simulate relative mouse movement
void MoveMouseRelative(int x, int y, WeaponConfig& weapon);
void weaponmove(WeaponConfig& weapon);
void checkMouseWheel();
void superglide();
void fastLoot();