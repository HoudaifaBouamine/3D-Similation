#pragma once
#include "libreries_include.h"
#include "util.h"
#define PI 3.14159265359
// Data Strcutures defined here

struct App {

	SDL_Renderer* renderer;
	SDL_Window* window;

};

struct Rectangle {

	

	float x1, y1, x2, y2, x3, y3, x4, y4;
	SDL_Renderer* renderer;

	Rectangle(SDL_Renderer* renderer,short x,short y,short w,short h) {

		x1 = x;
		y1 = y;

		x2 = x + w;
		y2 = y;

		x3 = x;
		y3 = y + h;

		x4 = x + w;
		y4 = y + h;

		this->renderer = renderer;
	}

	void rotate(short ox,short oy,float angle) {

		rotatePoint(x1, y1, ox, oy, angle);
		rotatePoint(x2, y2, ox, oy, angle);
		rotatePoint(x3, y3, ox, oy, angle);
		rotatePoint(x4, y4, ox, oy, angle);

		
	}

	void draw() {

		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
		SDL_RenderDrawLine(renderer, x1, y1, x3, y3);
		SDL_RenderDrawLine(renderer, x4, y4, x2, y2);
		SDL_RenderDrawLine(renderer, x4, y4, x3, y3);


	
	}

};