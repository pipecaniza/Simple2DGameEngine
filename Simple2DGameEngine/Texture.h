#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>


class Texture
{
public:
	Texture();
	~Texture();
	/** Loads an image from specific path  and create SDL_Texture to be renderize by the GPU */
	bool LoadFromFile(std::string path);
	/** Deallocate the texture */
	void Destroy();
	/** Return the texture */
	SDL_Texture* GetTexture();
	/** Set the color modulation to the texture */
	void SetColorModulation(Uint8 r, Uint8 g, Uint8 b);
	/** Set Blend mode to the texture */
	void SetBlendMode(SDL_BlendMode blendMode);
	/** Set the alpha channel(transparency) to the texture */
	void SetAlpha(Uint8 alpha);


private:
	SDL_Texture* sTexture;
	int Weigth;
	int Height;
};

