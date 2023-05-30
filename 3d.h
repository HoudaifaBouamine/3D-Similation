#pragma once
#include "libreries_include.h"
// 3d logic write here
void clear_renderer(void);
















void runSimilation() {

	initSDL();
	initProgram();

	Rectangle rectangle(app.renderer,500,300,150,70);
	Rectangle square(app.renderer,400, 400, 80, 80);


	while (true) {

		clear_renderer();


		doInput();
		rectangle.draw();
		rectangle.rotate(650, 400,0.05);

		square.draw();
		square.rotate(440, 440, 0.15);

		SDL_RenderPresent(app.renderer);
		SDL_Delay(16);
	}

}














void clear_renderer() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

}