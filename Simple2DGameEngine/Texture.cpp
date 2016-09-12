#include "Texture.h"



Texture::Texture()
{
}


Texture::~Texture()
{
}

bool Texture::LoadFromFile(std::string path)
{
	auto img = IMG_Load(path.c_str());
	if (img == NULL) {
		//cout << "No se pudo cargar " << path.c_str() << ". " << SDL_GetError() << '\n';
		Log::WriteConsoleLog("asd");
		return NULL;
	}

	auto texture = SDL_CreateTextureFromSurface(sRenderer, img);

	SDL_FreeSurface(img);

	sTexture = texture;
}
