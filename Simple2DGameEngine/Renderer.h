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
	static Renderer* rRenderer;

	SDL_Window* sWindow;
	SDL_Renderer* sRenderer;
	int Weight;
	int Heigth;
	int Fps;

public:
	/** Initialize the renderer given the weight an heigth of the screen, and configure the renderer update with the fps number */
	bool Initialize(int fps, int weight, int heigth);
	/** Render the current render buffer on the screen, then clear the renderer */
	void Render();
	/** Add a texture to render buffer within the source and destination rectangles */
	void AddTextureToRender(SDL_Texture* texture, SDL_Rect* source = NULL, SDL_Rect* destination = NULL);
	/** Return the sRenderer to be used on Texture creation */
	static SDL_Renderer* GetRenderer();
	/** We need the same renderer in whole excecution, so we implement the singleton pattern */
	static Renderer* GetRendererInstance();

private:
	Renderer();
	~Renderer();
};

