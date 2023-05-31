#pragma once
#include "libreries_include.h"
// 3d logic write here
void clear_renderer(void);
















void runSimilation() {

	initSDL();
	initProgram();

	Rectangle rectangle(app.renderer,500,300,300,160);
	Rectangle square1(app.renderer,0, 0, 80, 80);
	Rectangle square2(app.renderer,0, 0, 80, 80);
	Rectangle square3(app.renderer,0, 0, 80, 80);
	Rectangle square4(app.renderer,0, 0, 80, 80);


	while (true) {

		clear_renderer();


		doInput();
		rectangle.rotate(650, 380,0.05);
		rectangle.draw();


		

		SDL_RenderPresent(app.renderer);
		SDL_Delay(16);
	}

}














void clear_renderer() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

}