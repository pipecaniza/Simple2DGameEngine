#include <SDL.h>
#include "easydl.h"
#include "Tank.h"

using namespace std;

const int W_SCREEN = 640;
const int H_SCREEN = 480;
const int TAM_IMAGEN = 32;

int main(int argc, char *argv[])
{
	Game game;

	game.start(W_SCREEN, H_SCREEN, 15, true);

	// Rect destino para pintar
	SDL_Rect DestR;
	DestR.x = W_SCREEN / 2 - TAM_IMAGEN / 2;
	DestR.y = H_SCREEN / 2 - TAM_IMAGEN / 2;
	DestR.w = TAM_IMAGEN;
	DestR.h = TAM_IMAGEN;

	Tanque *t = new Tanque(
		SDL_SCANCODE_UP,
		SDL_SCANCODE_DOWN,
		SDL_SCANCODE_LEFT,
		SDL_SCANCODE_RIGHT,
		DestR,
		game.loadImage("Jugador.bmp"));

	while (!game.quitEvent()) {
		t->update();
		t->draw(&game);

		game.update();
	}
	game.quit();

	return 0;
}
