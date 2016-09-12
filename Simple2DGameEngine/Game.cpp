#include "Game.h"



void Game::Initialize()
{
	GameRenderer->Initialize(60, 640, 480);
}

void Game::Update()
{
	auto timerFps = SDL_GetTicks();
	//SDL_PumpEvents();
	GameRenderer->Render();

	timerFps = SDL_GetTicks() - timerFps;

	if (timerFps < 1000 / 60) {
		SDL_Delay((1000 / 60) - timerFps);
	}
	
}

Game::Game()
{
	GameRenderer = Renderer::GetThisRenderer();
}


Game::~Game()
{
}
