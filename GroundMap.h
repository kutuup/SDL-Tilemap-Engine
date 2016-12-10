#pragma once
#include "Map.h"
#include "BaseMap.h"
#include"BaseMap.h"
class GroundMap : public Map
{
public:
	GroundMap();
	~GroundMap();
	void addMap(Map* map);
private:
	Map* map;
};

