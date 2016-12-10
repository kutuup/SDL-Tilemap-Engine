#pragma once
#include "SDL.h"
#include <vector>

class TileLibraryEntry
{
public:
	TileLibraryEntry();
	~TileLibraryEntry();
	void setImage(SDL_Surface* img);
	void setID(int id);
	int getID();
	SDL_Surface* getImage();
private:
	int id;
	SDL_Surface* image;
};

