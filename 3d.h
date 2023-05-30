#pragma once
#include "libreries_include.h"
// 3d logic write here
void clear_renderer(void);
















void runSimilation() {

	initSDL();
	initProgram();

	Rectangle rectangle(app.renderer,500,300,300,160);
	Rectangle square1(app.renderer,400, 400, 80, 80);
	Rectangle square2(app.renderer, 400, 400, 80, 80);
	Rectangle square3(app.renderer, 400, 400, 80, 80);
	Rectangle square4(app.renderer, 400, 400, 80, 80);


	while (true) {

		clear_renderer();


		doInput();
		rectangle.rotate(650, 380,0.5);
		rectangle.draw();


		square1.set_center(rectangle.x1, rectangle.y1);
		square1.rotate(rectangle.x1, rectangle.y1, 0.15);
		square1.draw();


		square2.set_center(rectangle.x2, rectangle.y2);
		square2.rotate(rectangle.x2, rectangle.y2, 0.15);
		square2.draw();


		square3.set_center(rectangle.x3, rectangle.y3);
		square3.rotate(rectangle.x3, rectangle.y3, 0.15);
		square3.draw();


		square4.set_center(rectangle.x4, rectangle.y4);
		square4.rotate(rectangle.x4, rectangle.y4, 0.15);
		square4.draw();

		SDL_RenderPresent(app.renderer);
		SDL_Delay(16);
	}

}














void clear_renderer() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

}