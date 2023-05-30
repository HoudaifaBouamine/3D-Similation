#pragma once
#include "libreries_include.h"
// 3d logic write here

void runSimilation() {

	initSDL();
	
	while (true) {

		SDL_RenderClear(app.renderer);
		SDL_RenderPresent(app.renderer);
	}

}