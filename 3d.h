#pragma once
#include "libreries_include.h"
// 3d logic write here
void clear_renderer(void);
















void runSimilation() {

	initSDL();
	initProgram();

	
	

	Cuboid cube(app.renderer,400,300,300,200,200,200);


	while (true) {

		clear_renderer();
		doInput();
		cube.rotate(cube.center, 0.015, 0.01, 0.01);

		cube.draw();

		SDL_RenderPresent(app.renderer);
		SDL_Delay(16);
	}

}














void clear_renderer() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

}