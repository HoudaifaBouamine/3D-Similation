#pragma once
#include "libreries_include.h"
// 3d logic write here

void runSimilation() {

	initSDL();
	initProgram();
	while (true) {

		SDL_RenderClear(app.renderer);
		doInput();
		SDL_RenderPresent(app.renderer);
	}

}