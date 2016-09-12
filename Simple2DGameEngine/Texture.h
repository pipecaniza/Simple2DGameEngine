#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>


class Texture
{
public:
	Texture();
	~Texture();

	bool LoadFromFile(std::string path);

private:
	SDL_Texture* sTexture;
};

