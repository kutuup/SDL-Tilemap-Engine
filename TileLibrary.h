#pragma once
#include "SDL.h"
#include <vector>
#include "TileLibraryEntry.h"
#include <string>

class TileLibrary
{
public:
	TileLibrary();
	~TileLibrary();
	SDL_Surface* getTile(int id);
	int LoadTiles(std::vector<std::string> tiles);
private:
	std::vector<TileLibraryEntry*> Tiles;
};

