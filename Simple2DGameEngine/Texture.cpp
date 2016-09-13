#include "Texture.h"
#include "Renderer.h"
#include "Log.h"



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
		Log::WriteConsoleLog(SDL_GetError());
		return NULL;
	}

	auto texture = SDL_CreateTextureFromSurface(Renderer::GetRenderer(), img);

	SDL_FreeSurface(img);

	sTexture = texture;
}

SDL_Texture* Texture::GetTexture()
{
	return sTexture;
}
