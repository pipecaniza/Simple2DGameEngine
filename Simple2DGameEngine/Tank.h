#pragma once
#include <SDL.h>
#include "easydl.h"
#include <string.h>
#include "Entity.h"


using namespace std;

class Tanque : public Entity
{
private:
	Uint8 tArriba, tAbajo, tIzquierda, tDerecha;
public:
	void update();

	void draw(Game *game);

	Tanque(Uint8 arriba, Uint8 abajo, Uint8 izquierda, Uint8 derecha, SDL_Rect r, SDL_Texture* t);
};

