#pragma once
#include "Tank.h"

using namespace std;

void Tanque::update() {
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[tDerecha]) {
		rot = 90;
		rect.x += 10;
	}
	else if (state[tIzquierda]) {
		rot = -90;
		rect.x -= 10;
	}
	else if (state[tArriba]) {
		rot = 0;
		rect.y -= 10;
	}
	else if (state[tAbajo]) {
		rot = 180;
		rect.y += 10;
	}
}

void Tanque::draw(Game1 *Game1) {
	Game1->draw(textura, rect, rot);
	Game1->drawRect(rect, 255, 0, 0);
}

Tanque::Tanque(Uint8 arriba, Uint8 abajo, Uint8 izquierda, Uint8 derecha, SDL_Rect r, SDL_Texture* t) {
	tArriba = arriba;
	tAbajo = abajo;
	tIzquierda = izquierda;
	tDerecha = derecha;
	rect = r;
	textura = t;
	rot = 0;
}

