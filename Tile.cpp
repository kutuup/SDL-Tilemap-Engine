#include "stdafx.h"
#include "Tile.h"
#include <string>
#include "SDL.h"

Tile::Tile(SDL_Surface* image, int sideLength)
{
	this->image = SDL_CreateRGBSurface(SDL_HWSURFACE, sideLength, sideLength, 32, 255, 0, 0, 255);
	this->image = image;
	this->sideLength = sideLength;
	//SDL_FillRect(image, NULL, 255);
	//image = SDL_LoadBMP("img/grass.bmp");
	std::string x = SDL_GetError();
}


Tile::~Tile()
{
}

void Tile::changeType(SDL_Surface* image, tileType newType)
{
	if (newType == STAGE)
	{
		blocked = true;
	}
	this->image = image;
	this->type = newType;
}

SDL_Surface* Tile::getImage()
{
	return image;
}

tileType Tile::getType()
{
	return type;
}
