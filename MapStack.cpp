#include "stdafx.h"
#include "MapStack.h"
#include "BaseMap.h"
#include "GroundMap.h"
#include "Tile.h"
#include "SDL.h"
#include "Map.h"
#include <vector>
#include <exception>

MapStack::MapStack()
{
	this->stack = new std::vector<Map*>();
	//this->surface = SDL_CreateRGBSurface(0, stack->at(0)->getWidth() * stack->at(0)->getTileSize(), stack->at(0)->getHeight() * stack->at(0)->getTileSize(), 32, 0, 0, 0, 0);
	this->surface = SDL_CreateRGBSurface(0,1920,1080, 32, 0, 0, 0, 0);
	updatePending = true;
}

MapStack::MapStack(int x, int y, int tilew)
{
	this->stack = new std::vector<Map*>();
	this->surface = SDL_CreateRGBSurface(0, x * tilew, y * tilew, 32, 0, 0, 0, 0);
	//this->surface = SDL_CreateRGBSurface(0,1920,1080, 32, 0, 0, 0, 0);
	updatePending = true;
}

bool MapStack::addMapToStack(Map* Map)
{
	try
	{
		this->stack->push_back(Map);
	}
	catch (std::exception ex)
	{
		return false;
	}
	
	return true;
}

void MapStack::setSurface(SDL_Surface* s)
{
	surface = s;
}

SDL_Surface* MapStack::getSurface()
{
	return surface;
}

SDL_Surface* MapStack::getSurface(int w, int h)
{
	getBufferSurface = new SDL_Surface();
	SDL_Rect* portion = new SDL_Rect();
	portion->w = w;
	portion->h = h;
	SDL_BlitSurface(surface, portion, getBufferSurface, NULL);
	return getBufferSurface;
}

bool MapStack::isUpdatePending()
{
	return updatePending;
}

void MapStack::setUpdatePending(bool flag)
{
	this->updatePending = flag;
}

void MapStack::drawMap(int index)
{
	Map* temp = stack->at(index);
	{
		std::vector<std::vector<Tile>>* t = temp->GetMap();
		{
			int tileOffsetH = 0;
			int tileOffsetV = 0;
			for each  (std::vector<Tile> x in *t)
			{
				for each  (Tile y in x)
				{
					SDL_Rect rect;
					rect.x = tileOffsetH;
					rect.y = tileOffsetV;
					//surface->locked = true;
					int debug = SDL_BlitSurface(y.getImage(), NULL, surface, &rect);
					tileOffsetH += temp->getTileSize();
				}
				tileOffsetH = 0;
				tileOffsetV += temp->getTileSize();
			}
		}
	}
}

MapStack::~MapStack()
{
}
