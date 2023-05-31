#pragma once
#include "libreries_include.h"
// 3d logic write here
void clear_renderer(void);
















void runSimilation() {

	initSDL();
	initProgram();

	
	

	Cuboid cube(app.renderer,400,300,300,200,200,200);

	Cuboid cube0(app.renderer, 0, 0, 0, 40, 40, 40);
	Cuboid cube1(app.renderer, 0,0,0, 40, 40, 40);
	Cuboid cube2(app.renderer, 0,0,0, 40, 40, 40);
	Cuboid cube3(app.renderer, 0,0,0, 40, 40, 40);
	Cuboid cube4(app.renderer, 0,0,0, 40, 40, 40);
	Cuboid cube5(app.renderer, 0, 0, 0, 40, 40, 40);
	Cuboid cube6(app.renderer, 0, 0, 0, 40, 40, 40);
	Cuboid cube7(app.renderer, 0, 0, 0, 40, 40, 40);


	while (true) {

		clear_renderer();
		doInput();




		cube.rotate(cube.center, 0.015, 0.02, 0.01);
		cube.draw();

		cube0.set_center(cube.points[0]);
		cube1.set_center(cube.points[1]);
		cube2.set_center(cube.points[2]);
		cube3.set_center(cube.points[3]);
		cube4.set_center(cube.points[4]);
		cube5.set_center(cube.points[5]);
		cube6.set_center(cube.points[6]);
		cube7.set_center(cube.points[7]);

		cube0.rotate(cube0.center, 0.03, 0.02, 0.025);
		cube1.rotate(cube1.center, 0.02, 0.03, 0.025);
		cube2.rotate(cube2.center, 0.02, 0.02, 0.015);
		cube3.rotate(cube3.center, 0.01, 0.02, 0.005);
		cube4.rotate(cube4.center, 0.02, 0.04, 0.025);
		cube5.rotate(cube5.center, 0.02, 0.02, 0.015);
		cube6.rotate(cube6.center, 0.013, 0.02, 0.025);
		cube7.rotate(cube7.center, 0.02, 0.035, 0.015);

		cube0.draw();
		cube1.draw();
		cube2.draw();
		cube3.draw();
		cube4.draw();
		cube5.draw();
		cube6.draw();
		cube7.draw();



		SDL_RenderPresent(app.renderer);
		SDL_Delay(16);
	}

}














void clear_renderer() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

}