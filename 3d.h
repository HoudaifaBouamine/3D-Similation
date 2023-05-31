#pragma once
#include "libreries_include.h"
#include "benchmark.h"
// 3d logic write here
void clear_renderer(void);
void showtest(Benchmark test);















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

	Benchmark test;

	while (true) {

		test.start();


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

		cube0.rotate(cube0.center, 0.04, 0.05, 0.025);
		cube1.rotate(cube1.center, 0.02, 0.03, 0.025);
		cube2.rotate(cube2.center, 0.07, 0.04, 0.015);
		cube3.rotate(cube3.center, 0.01, 0.02, 0.075);
		cube4.rotate(cube4.center, 0.02, 0.04, 0.025);
		cube5.rotate(cube5.center, 0.02, 0.08, 0.015);
		cube6.rotate(cube6.center, 0.013, 0.02, 0.025);
		cube7.rotate(cube7.center, 0.02, 0.035, 0.015);

		cube0.draw(255,0,0);// red
		cube1.draw(255,255,0);//yellow
		cube2.draw(255,0,255);// purpel
		cube3.draw(0,255,0);
		cube4.draw(0,255,255);
		cube5.draw(0,0,255);
		cube6.draw(100,200,100);
		cube7.draw(200,50,50);



		SDL_RenderPresent(app.renderer);

		test.end();
		
		showtest(test);

		SDL_Delay(16);
	}

}












void showtest(Benchmark test) {


	static int cpt_avg = 0;
	cpt_avg++;
	static long long avg = 0;
	avg += test.time;
	static int cpt = 0;
	cpt++;
	static int sum = 0;
	sum += test.time;

	//printf("Prosses time : %d            \n" ,test.time);
	if (cpt >= 20) {

		clear_screen();
		printf("Prosses time : %d            \n", sum / 20);
		sum = 0;
		cpt = 0;
	}

	if (cpt_avg >= 600) {
		printf("Prosses time(AVG) : %d            \n", avg / 600);
		cpt_avg = 0;
		avg = 0;
	}
}

void clear_renderer() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

}