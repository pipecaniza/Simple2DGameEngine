#pragma once
#include "easydl.h"

using namespace std;

bool Game1::start(int w, int h, int fps, bool hw)
{/*
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "Error iniciando SDL: " << SDL_GetError() << '\n';
		return false;
	}

	window = SDL_CreateWindow(
		"SDL Base Project",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		w, h,
		0);

	if (window == NULL) {
		cout << "Error creando la ventana: " << SDL_GetError() << '\n';
		return false;
	}
	*/
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		cout << "Error cargando SDL_Image: " << IMG_GetError() << '\n';
		return false;
	}

	//renderer = SDL_CreateRenderer(window, -1, hw ? SDL_RENDERER_ACCELERATED : SDL_RENDERER_SOFTWARE);

	FPS = fps;
	return true;
}

void Game1::draw(SDL_Texture *t, SDL_Rect &r, float rot)
{
	SDL_RenderCopyEx(renderer, t, NULL, &r, rot, NULL, SDL_FLIP_NONE);
}

void Game1::drawRect(SDL_Rect &rect, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderDrawRect(renderer, &rect);
}

void Game1::update()
{
	auto timerFps = SDL_GetTicks();
	SDL_PumpEvents();
	SDL_RenderPresent(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	timerFps = SDL_GetTicks() - timerFps;

	if (timerFps < 1000 / FPS) {
		SDL_Delay((1000 / FPS) - timerFps);
	}
}

void Game1::quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Texture* Game1::loadImage(string path) {
	auto img = IMG_Load(path.c_str());
	if (img == NULL) {
		cout << "No se pudo cargar " << path.c_str() << ". " << SDL_GetError() << '\n';
		return NULL;
	}

	auto texture = SDL_CreateTextureFromSurface(renderer, img);

	SDL_FreeSurface(img);

	return texture;
}

bool Game1::quitEvent()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return true;
		}
	}
	return false;
}

