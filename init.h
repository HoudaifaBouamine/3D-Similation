#pragma once
#include "libreries_include.h"
#include "defs.h"
#include "global.h"
// initielize the program

void initSDL() {

	int rendererFlags = SDL_RENDERER_ACCELERATED, windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("3D Renderer", 200, 50, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window) {

		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);

	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

}

void initProgram() {
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

}