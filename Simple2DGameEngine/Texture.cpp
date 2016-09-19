#include "Texture.h"
#include "Renderer.h"
#include "Log.h"



Texture::Texture()
{
	sTexture = NULL;
	Weigth = 0;
	Height = 0;
}


Texture::~Texture()
{
	Destroy();
}

bool Texture::LoadFromFile(std::string path)
{
	auto surface = IMG_Load(path.c_str());
	if (surface == NULL) {
		//cout << "No se pudo cargar " << path.c_str() << ". " << SDL_GetError() << '\n';
		Log::WriteConsoleLog(SDL_GetError());
		return NULL;
	}
	//SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, ));
	auto texture = SDL_CreateTextureFromSurface(Renderer::GetRenderer(), surface);	
	Weigth = surface->w;
	Height = surface->h;
	SDL_FreeSurface(surface);
	sTexture = texture;
	SetBlendMode(SDL_BLENDMODE_BLEND);
}

void Texture::Destroy()
{
	if (sTexture != NULL)
	{
		SDL_DestroyTexture(sTexture);
		sTexture = NULL;
		Weigth = 0;
		Height = 0;
	}
}

SDL_Texture* Texture::GetTexture()
{
	return sTexture;
}

void Texture::SetColorModulation(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetTextureColorMod(sTexture, r, g, b);
}

void Texture::SetBlendMode(SDL_BlendMode blendMode)
{
	SDL_SetTextureBlendMode(sTexture, blendMode);
}

void Texture::SetAlpha(Uint8 alpha) 
{
	SDL_SetTextureAlphaMod(sTexture, alpha);
}