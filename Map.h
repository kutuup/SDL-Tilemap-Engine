#pragma once

#include "SDL.h"
#include "Tile.h"
#include "BaseMap.h"
#include <vector>
#include "TileLibrary.h"

class Map : public BaseMap
{
public:
	Map(int, int, int, TileLibrary* library);
	~Map();

	std::vector<std::vector<Tile>>* GetMap();
	int getTileSize();
	int getWidth();
	int getHeight();
private:
	int id;
	int width;
	int height;
	int tileSize;
	std::vector<std::vector<Tile>>* tiles;
	TileLibrary* library;
};

