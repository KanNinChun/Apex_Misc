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
	SetConsoleTitle("Apex小工具 v1.0");
	compileDateTime();
	std::cout <<"\n" << std::endl;
	std::cout << "#--------------------------------------------------#" << std::endl;
	std::cout << "按 INSERT 鍵關閉成個Script。" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "撳一下 NUMPAD 0 取消啟用" << std::endl;
	std::cout << "撳一下 NUMPAD 1 啟用 Flatline" << std::endl;
	std::cout << "撳一下 NUMPAD 2 啟用 Car" << std::endl;
	std::cout << "撳一下 NUMPAD 3 啟用 Volt" << std::endl;
	std::cout << "撳住 XBUTTON2   啟用快速執野" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "#--------------------------------------------------#" << std::endl;
	std::cout << "向下滾動滑鼠滾輪輔助你superglide，它會自動幫你按下空格鍵和蹲鍵， 最好將FPS鎖定在 144" << std::endl;

}