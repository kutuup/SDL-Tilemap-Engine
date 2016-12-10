#pragma once
#include "BaseMap.h"
#include <vector>
#include "SDL.h"
#include "Map.h"
class MapStack
{
public:
	MapStack();
	MapStack(int x, int y, int tilew);
	~MapStack();
	bool addMapToStack(Map* Map);
	void drawMap(int index);
	SDL_Surface* getSurface();
	SDL_Surface* getSurface(int w, int h);
	void setSurface(SDL_Surface* s);
	bool isUpdatePending();
	void setUpdatePending(bool flag);
private:
	std::vector<Map*>* stack;
	SDL_Surface* surface;
	SDL_Surface* getBufferSurface;
	bool updatePending;
};

