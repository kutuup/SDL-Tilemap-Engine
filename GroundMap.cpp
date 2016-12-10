#include "stdafx.h"
#include "GroundMap.h"
#include "Map.h"
#include "BaseMap.h"
#include "TileLibrary.h"

GroundMap::GroundMap() : Map(50, 50, 50, new TileLibrary())
{
}

void GroundMap::addMap(Map* map)
{
	this->map = map;
}

GroundMap::~GroundMap()
{
}
