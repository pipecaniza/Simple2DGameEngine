#include "Renderer.h"
#include "Log.h"
#include <SDL_image.h>

Renderer* Renderer::rRenderer = nullptr;

bool Renderer::Initialize(int fps, int weight, int heigth)
{
	Weight = weight;
	Heigth = heigth;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Log::WriteConsoleLog(SDL_GetError());
		return false;
	}

	sWindow = SDL_CreateWindow(
		"First",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		Weight,
		Heigth,
		0
	);

	if (sWindow == NULL)
	{
		Log::WriteConsoleLog(SDL_GetError());
		return false;
	}

	sRenderer = SDL_CreateRenderer(sWindow, -1, SDL_RENDERER_ACCELERATED);

	if (sRenderer == NULL)
	{
		Log::WriteConsoleLog(SDL_GetError());
		return false;
	}

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		Log::WriteConsoleLog(IMG_GetError());
		return false;
	}

	Fps = fps;

	return true;
}

void Renderer::Render()
{
	SDL_RenderPresent(sRenderer);
	SDL_SetRenderDrawColor(sRenderer, 0, 0, 0, 0);
	SDL_RenderClear(sRenderer);	
}


void Renderer::AddTextureToRender(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination)
{
	SDL_RenderCopy(
		sRenderer, 
		texture, 
		source, 
		destination
	);
}

SDL_Renderer* Renderer::GetRenderer()
{
	return rRenderer->sRenderer;
}

Renderer* Renderer::GetRendererInstance()
{
	if (rRenderer == nullptr)
		rRenderer = new Renderer();

	return rRenderer;
}

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}
