#include <SDL.h>
#include "easydl.h"
#include "Game.h"
#include "Tank.h"
#include "Texture.h"

using namespace std;

const int W_SCREEN = 640;
const int H_SCREEN = 480;
const int TAM_IMAGEN = 32;

int main(int argc, char *argv[])
{
	Game1 Game1;
	Game g;
	g.Initialize();

	//Game1.start(W_SCREEN, H_SCREEN, 15, true);

	// Rect destino para pintar
	SDL_Rect DestR;
	DestR.x = W_SCREEN / 2 - TAM_IMAGEN / 2;
	DestR.y = H_SCREEN / 2 - TAM_IMAGEN / 2;
	DestR.w = TAM_IMAGEN;
	DestR.h = TAM_IMAGEN;

	SDL_Rect DestR2;
	DestR2.x = W_SCREEN / 3 - TAM_IMAGEN / 2;
	DestR2.y = H_SCREEN / 3 - TAM_IMAGEN / 2;
	DestR2.w = TAM_IMAGEN;
	DestR2.h = TAM_IMAGEN;

	
	//SDL_Texture* texture = Game1.loadImage("C:\\Users\\JuanFelipe\\Documents\\Visual Studio 2015\\Projects\\Simple2DGameEngine\\Simple2DGameEngine\\Jugador.bmp");
	Texture texture;
	texture.LoadFromFile("Jugador.bmp");
	texture.SetColorModulation(150, 30, 240);
	g.GameRenderer->AddTextureToRender(texture.GetTexture(), NULL, &DestR);
	texture.SetAlpha(100);
	g.GameRenderer->AddTextureToRender(texture.GetTexture(), NULL, &DestR2);
	
	g.Update();
	while (true) {
		
	}

	return 0;
}
