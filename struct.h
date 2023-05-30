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

	

	float x1, y1, x2, y2, x3, y3, x4, y4,xc,yc,w,h;
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

		xc = x + w / 2;
		yc = y + h / 2;

		this->w = w;
		this->h = h;
	}

	void set_center(short center_x,short center_y) {

		float dx = center_x - xc;
		float dy = center_y - yc;

		x1 += dx;
		x2 += dx;
		x3 += dx;
		x4 += dx;

		y1 += dy;
		y2 += dy;
		y3 += dy;
		y4 += dy;

		xc = center_x;
		yc = center_y;
	}

	void rotate(short ox,short oy,float angle) {

		rotatePoint(x1, y1, ox, oy, angle);
		rotatePoint(x2, y2, ox, oy, angle);
		rotatePoint(x3, y3, ox, oy, angle);
		rotatePoint(x4, y4, ox, oy, angle);

		rotatePoint(xc, yc, ox, oy, angle);

		
	}

	void draw() {

		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
		SDL_RenderDrawLine(renderer, x1, y1, x3, y3);
		SDL_RenderDrawLine(renderer, x4, y4, x2, y2);
		SDL_RenderDrawLine(renderer, x4, y4, x3, y3);


	
	}

};