#pragma once
#include "Renderer.h"

class Game
{
public:
	Renderer* GameRenderer;
public:
	void Initialize();
	void Update();
	Game();
	~Game();
};

