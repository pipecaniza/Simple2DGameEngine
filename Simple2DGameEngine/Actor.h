#pragma once
#include <SDL.h>

class Actor
{
protected:
	bool isVisible;

public:
	virtual void Tick(Uint32 DeltaSeconds) = 0;

	Actor();
	~Actor();
};

