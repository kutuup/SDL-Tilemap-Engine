#include "stdafx.h"
#include "Map.h"
#include <vector>
#include "TileLibrary.h"

bool FORCEDIRTBORDERS = true;

Map::Map(int w, int h, int newTileSize, TileLibrary* library)
{
	tileSize = newTileSize;
	tiles = new std::vector<std::vector<Tile>>();
	this->library = library;
	this->width = w;
	this->height = h;
	for (int x = 0; x < w; x++)
	{
		std::vector<Tile>* temp = new std::vector<Tile>();
		for (int y = 0; y < h; y++)
		{
			if (!FORCEDIRTBORDERS)
			{
				Tile* tempTile = new Tile(library->getTile(0), tileSize);
				temp->push_back(*tempTile);
			}
			else if(FORCEDIRTBORDERS)
			{
				Tile* tempTile;
				if (y == 0 || y == h -1 || x == 0 || x == w -1)
				{
					tempTile = new Tile(library->getTile(1), tileSize);
					
				}
				else
				{
					tempTile = new Tile(library->getTile(0), tileSize);
				}
				//this function creates some test tiles
				if (y == 5 && x == 5)
				{
					tempTile = new Tile(library->getTile(2), tileSize);
				}
				temp->push_back(*tempTile);
			}
		}
		tiles->push_back(*temp);
	}
}

int Map::getTileSize()
{
	return tileSize;
}

int Map::getWidth()
{
	return width;
}

int Map::getHeight()
{
	return height;
}

std::vector<std::vector<Tile>>* Map::GetMap()
{
	return tiles;
}


Map::~Map()
{

}
