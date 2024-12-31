#pragma once
#include <vector>
#include <atomic>

struct WeaponConfig {
    std::vector<double> patternX;
    std::vector<double> patternY;
    int shotsFired;
    int maxShots;
    int sleep;
    int moveSleep;
    int x;
    int y;
};


extern WeaponConfig flatline;
extern WeaponConfig volt; 
extern WeaponConfig car;
extern std::atomic<WeaponConfig*> currentWeapon;

void switchWeapon();
