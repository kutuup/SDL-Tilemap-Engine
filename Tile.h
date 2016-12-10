#pragma once

#include "SDL.h"

enum tileType
{
	GROUND, PATH, STAGE
};

class Tile
{
public:
	Tile(SDL_Surface* image, int sideLength);
	~Tile();
	SDL_Surface* getImage();
	tileType getType();
	void changeType(SDL_Surface* type, tileType newType);
private:
	SDL_Surface* image;
	int sideLength;
	bool blocked;
	tileType type;
};

