#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

class Game1
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	int FPS;

public:
	bool start(int w, int h, int fps, bool hw);

	void update();

	void draw(SDL_Texture *t, SDL_Rect &r, float rot);

	void drawRect(SDL_Rect &rect, Uint8 r, Uint8 g, Uint8 b);

	void quit();

	SDL_Texture* loadImage(string path);

	bool quitEvent();
};
