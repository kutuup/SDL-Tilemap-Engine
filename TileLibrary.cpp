#include "stdafx.h"
#include "TileLibrary.h"
#include "SDL.h"
#include <vector>
#include <string>

SDL_Surface* TileLibrary::getTile(int id)
{
	for (int count = 0; count < Tiles.size(); count++)
	{
		if (Tiles.at(count)->getID() == id)
		{
			return(Tiles[count]->getImage());
		}
	}
}

int TileLibrary::LoadTiles(std::vector<std::string> tiles)
{
	int count;
	for (count = 0; count < tiles.size(); count++)
	{
		TileLibraryEntry* newEntry = new TileLibraryEntry();
		newEntry->setID(count);
		std::string y = tiles.at(count);
		SDL_Surface* temp = SDL_LoadBMP(y.c_str());
		std::string x = SDL_GetError();
		newEntry->setImage(temp);
		Tiles.push_back(newEntry);
	}
	return count;
}

TileLibrary::TileLibrary()
{
}


TileLibrary::~TileLibrary()
{
}
