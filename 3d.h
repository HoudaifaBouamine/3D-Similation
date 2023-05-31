#pragma once
#include "libreries_include.h"
// 3d logic write here
void clear_renderer(void);
















void runSimilation() {

	initSDL();
	initProgram();

	
	

	Point c;
	c.x = 150;
	c.y = 150;
	c.z = 150;

	Cuboid cube(app.renderer,100,100,100,100,100,100);


	while (true) {

		clear_renderer();
		doInput();
		cube.rotate(c, 0.01, 0.01, 0.01);

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