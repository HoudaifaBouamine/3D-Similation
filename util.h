#pragma once
// Util functions defined here
#include <cmath>
#include "struct.h"
#include <Windows.h>

void rotatePoint_OZ(float& x, float& y, short ox, short oy, float angle) {

	float dx = x - ox;
	float dy = y - oy;

	float new_dx = dx * cos(angle) - dy * sin(angle);
	float new_dy = dx * sin(angle) + dy * cos(angle);

	x = ox + new_dx;
	y = oy + new_dy;
}


void clear_screen()

{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}
