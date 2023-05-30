#pragma once
#include "libreries_include.h"
// Util functions defined here

void rotatePoint(float& x, float& y, short ox, short oy, float angle) {

	float dx = x - ox;
	float dy = y - oy;

	float new_dx = dx * cos(angle) - dy * sin(angle);
	float new_dy = dx * sin(angle) + dy * cos(angle);

	x = ox + new_dx;
	y = oy + new_dy;
}
