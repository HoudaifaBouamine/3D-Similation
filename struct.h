#pragma once
#include "libreries_include.h"
#include "util.h"
#define PI 3.14159265359
// Data Strcutures defined here

struct App {

	SDL_Renderer* renderer;
	SDL_Window* window;

};

struct Point {

	float x, y, z;
};

struct Rectangle {

	
	Point points[4];
	float xc,yc,w,h;
	SDL_Renderer* renderer;

	Rectangle(SDL_Renderer* renderer,short x,short y,short w,short h) {

		points[0].x = x;
		points[0].y = y;

		points[1].x = x + w;
		points[1].y = y;

		points[2].x = x;
		points[2].y = y + h;

		points[3].x = x + w;
		points[3].y = y + h;

		this->renderer = renderer;

		xc = x + w / 2;
		yc = y + h / 2;

		this->w = w;
		this->h = h;
	}

	void set_center(short center_x,short center_y) {

		float dx = center_x - xc;
		float dy = center_y - yc;

		points[0].x += dx;
		points[1].x += dx;
		points[2].x += dx;
		points[3].x += dx;

		points[0].y += dy;
		points[1].y += dy;
		points[2].y += dy;
		points[3].y += dy;

		xc = center_x;
		yc = center_y;
	}

	void rotate(short ox,short oy,float angle) {

		rotatePoint(points[0].x, points[0].y, ox, oy, angle);
		rotatePoint(points[1].x, points[1].y, ox, oy, angle);
		rotatePoint(points[2].x, points[2].y, ox, oy, angle);
		rotatePoint(points[3].x, points[3].y, ox, oy, angle);

		rotatePoint(xc, yc, ox, oy, angle);

		
	}

	void draw() {

		SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[1].x, points[1].y);
		SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[2].x, points[2].y);
		SDL_RenderDrawLine(renderer,points[3].x, points[3].y, points[1].x, points[1].y);
		SDL_RenderDrawLine(renderer,points[3].x, points[3].y, points[2].x, points[2].y);


	
	}

};
