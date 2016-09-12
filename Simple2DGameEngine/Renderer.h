#include <SDL.h>
#include <string>

#pragma once
class Renderer
{
private:
	static const int W_SCREEN = 640;
	static const int H_SCREEN = 480;
	static const int TAM_IMAGEN = 32;

private:
	SDL_Window* sWindow;
	SDL_Renderer* sRenderer;
	int Weight;
	int Heigth;
	int Fps;

public:
	bool Initialize(int fps);
	void Render();
	void AddTextureToRender(SDL_Texture* texture, SDL_Rect* source = NULL, SDL_Rect* destination = NULL);
	SDL_Texture* Renderer::loadImage(std::string path);

	Renderer(int weight, int heigth);
	Renderer();
	~Renderer();
};

