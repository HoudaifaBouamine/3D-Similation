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


	void rotatePoint_OZ(Point originPoint, float angle) {

		float dx = this->x - originPoint.x;
		float dy = this->y - originPoint.y;

		float new_dx = dx * cos(angle) - dy * sin(angle);
		float new_dy = dx * sin(angle) + dy * cos(angle);

		this->x = originPoint.x + new_dx;
		this->y = originPoint.y + new_dy;
	}

	void rotatePoint_OY(Point originPoint, float angle) {

		float dx = this->x - originPoint.x;
		float dz = this->z - originPoint.z;

		float new_dx = dx * cos(angle) - dz * sin(angle);
		float new_dz = dx * sin(angle) + dz * cos(angle);

		this->x = originPoint.x + new_dx;
		this->z = originPoint.z + new_dz;
	}

	void rotatePoint_OX(Point originPoint, float angle) {

		float dy = this->y - originPoint.y;
		float dz = this->z - originPoint.z;

		float new_dy = dy * cos(angle) - dz * sin(angle);
		float new_dz = dy * sin(angle) + dz * cos(angle);

		this->y = originPoint.y + new_dy;
		this->z = originPoint.z + new_dz;
	}

	void rotatePoint(Point originPoint, float angleOX, float angleOY, float angleOZ) {


		rotatePoint_OX(originPoint, angleOX);
		rotatePoint_OY(originPoint, angleOY);
		rotatePoint_OZ(originPoint, angleOZ);

	}

	void move(float dx,float dy,float dz) {

		x += dx;
		y += dy;
		z += dz;

	}

	void moveBack(float dx, float dy, float dz) {

		x += dx;
		y += dy;
		z += dz;

		if (x > SCREEN_WIDTH) {

			x -= SCREEN_WIDTH;
		}
		if (y > SCREEN_HEIGHT)
		{
			y -= SCREEN_HEIGHT;
		}
	}
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

		rotatePoint_OZ(points[0].x, points[0].y, ox, oy, angle);
		rotatePoint_OZ(points[1].x, points[1].y, ox, oy, angle);
		rotatePoint_OZ(points[2].x, points[2].y, ox, oy, angle);
		rotatePoint_OZ(points[3].x, points[3].y, ox, oy, angle);

		rotatePoint_OZ(xc, yc, ox, oy, angle);

		
	}

	void draw() {

		SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[1].x, points[1].y);
		SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[2].x, points[2].y);
		SDL_RenderDrawLine(renderer,points[3].x, points[3].y, points[1].x, points[1].y);
		SDL_RenderDrawLine(renderer,points[3].x, points[3].y, points[2].x, points[2].y);


	
	}

};

struct Cuboid {

	Point points[8];
	Point center;
	float  w, h, d;
	SDL_Renderer* renderer;

	Cuboid(SDL_Renderer* renderer, short x, short y, short z, short w, short h, short d) {

		this->renderer = renderer;

		points[0].x = x;
		points[0].y = y;
		points[0].z = z;


		points[1].x = x + w;
		points[1].y = y;
		points[1].z = z;


		points[2].x = x;
		points[2].y = y + h;
		points[2].z = z;


		points[3].x = x + w;
		points[3].y = y + h;
		points[3].z = z;


		points[4].x = x;
		points[4].y = y;
		points[4].z = z + d;


		points[5].x = x + w;
		points[5].y = y;
		points[5].z = z + d;


		points[6].x = x;
		points[6].y = y + h;
		points[6].z = z + d;


		points[7].x = x + w;
		points[7].y = y + h;
		points[7].z = z + d;


	}

	void set_center(short center_x, short center_y, short center_z) {

		float dx = center_x - center.x;
		float dy = center_y - center.y;
		float dz = center_z - center.z;

		points[0].x += dx;
		points[1].x += dx;
		points[2].x += dx;
		points[3].x += dx;
		points[4].x += dx;
		points[5].x += dx;
		points[6].x += dx;
		points[7].x += dx;

		points[0].y += dy;
		points[1].y += dy;
		points[2].y += dy;
		points[3].y += dy;
		points[4].y += dy;
		points[5].y += dy;
		points[6].y += dy;
		points[7].y += dy;

		points[0].z += dz;
		points[1].z += dz;
		points[2].z += dz;
		points[3].z += dz;
		points[4].z += dz;
		points[5].z += dz;
		points[6].z += dz;
		points[7].z += dz;

		center.x = center_x;
		center.y = center_y;
		center.z = center_z;
	}

	void rotate(Point origin,float angleOX,float angleOY,float angleOZ) {

		for (size_t i = 0; i < 8; i++)
		{
			points[i].rotatePoint_OX(origin, angleOX);
			points[i].rotatePoint_OY(origin, angleOY);
			points[i].rotatePoint_OZ(origin, angleOZ);
		}
	}

	void draw() {

		for (char i = 0; i < 8; i++)
		{
			SDL_RenderDrawPoint(this->renderer, points[i].x, points[i].y);
		}

	}
};
