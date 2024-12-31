#include "menu.h"
#include <iostream>
#include <Windows.h>
const void compileDateTime() noexcept {

	const char* compileDate = __DATE__;
	const char* compileTime = __TIME__;

	// Parse the __DATE__ macro (e.g., "Oct 24 2024")
	std::tm tm = {};
	std::istringstream ss(compileDate);
	ss >> std::get_time(&tm, "%b %d %Y");

	// Adjust month to be 1-based (0-11 range in std::tm)
	tm.tm_mon += 1;

	printf("[+]Compile on: %02d/%02d/%04d %s", tm.tm_mday, tm.tm_mon, tm.tm_year + 1900, compileTime);

}

const void menu()
{
	SetConsoleTitle("This is kinda SuS v1.0");
	std::cout << "RecoilMaster v1.0 :)" << std::endl;
	compileDateTime();
	std::cout <<"\n" << std::endl;
	std::cout << "#--------------------------------------------------#" << std::endl;
	std::cout << "Starting anti-recoil script. Press INSERT to stop." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Press NUMPAD 0 to deactive script" << std::endl;
	std::cout << "Press NUMPAD 1 to active Flatline" << std::endl;
	std::cout << "Press NUMPAD 2 to active Car" << std::endl;
	std::cout << "Press NUMPAD 3 to active Volt" << std::endl;
	std::cout << "Holding XBUTTON2 to use fast Loot" << std::endl;
	std::cout << "Scroll your mouse wheel down to auto superglide" << std::endl;

}