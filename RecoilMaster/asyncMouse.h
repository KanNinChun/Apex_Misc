#pragma once
#include <windows.h>
#include <ctime>


LRESULT CALLBACK Mouse(int nCode, WPARAM wParam, LPARAM lParam);

int GetScrollDelta();
