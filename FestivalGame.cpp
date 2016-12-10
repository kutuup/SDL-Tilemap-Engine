// FestivalGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"
#include "Map.h"
#include "MapStack.h"
#include "TileLibrary.h"
#include <vector>
#include <string>

TileLibrary* mainTileLib;
MapStack* mainStack;
SDL_Surface* screen;
int CAMERA_X;
int CAMERA_Y;
int SCREEN_SCROLL_SPEED;
int SCREENWIDTH;
int SCREENHEIGHT;
int TILEWIDTH = 25;
int TILECOUNT_X;
int TILECOUNT_Y;
bool quit;

void LoadGraphics()
{
	SCREENHEIGHT = 600;
	SCREENWIDTH = 800;
	SCREEN_SCROLL_SPEED = 1;
	screen = SDL_SetVideoMode(SCREENWIDTH, SCREENHEIGHT, 0, 0);
	mainTileLib = new TileLibrary();
	std::vector<std::string>* imageNames = new std::vector<std::string>();
	imageNames->push_back("img/grass.bmp");
	imageNames->push_back("img/dirt.bmp");
	imageNames->push_back("img/stagefront.bmp");
	mainTileLib->LoadTiles(*imageNames);
}

void LoadMaps()
{
	TILECOUNT_X = 100;
	TILECOUNT_Y = 100;
	mainStack = new MapStack(TILECOUNT_X, TILECOUNT_Y, TILEWIDTH);
	Map *mainMap = new Map(TILECOUNT_X, TILECOUNT_Y, TILEWIDTH, mainTileLib);
	mainStack->addMapToStack(mainMap);
	mainStack->drawMap(0);
}

void ProcessKeys(Uint8* keystate)
{
	if (keystate[SDLK_RIGHT])
	{
		if (CAMERA_X < (TILECOUNT_X * TILEWIDTH) - SCREENWIDTH)
		{
			CAMERA_X += 1 * SCREEN_SCROLL_SPEED;
		}
	}
	if (keystate[SDLK_LEFT])
	{
		if (CAMERA_X > 0)
		{
			CAMERA_X -= 1 * SCREEN_SCROLL_SPEED;
		}
	}
	if (keystate[SDLK_UP])
	{
		if (CAMERA_Y > 0)
		{
			CAMERA_Y -= 1 * SCREEN_SCROLL_SPEED;
		}
	}
	if (keystate[SDLK_DOWN])
	{
		if (CAMERA_Y < (TILECOUNT_Y * TILEWIDTH) - SCREENHEIGHT)
		{
			CAMERA_Y += 1 * SCREEN_SCROLL_SPEED;
		}
	}
	if (keystate[SDLK_ESCAPE])
	{
		quit = true;
	}
}

int main(int argc, char *argv[])
{
	quit = false;
	SDL_Init(SDL_INIT_EVERYTHING);
	LoadGraphics();
	LoadMaps();
	SDL_UnlockSurface(screen);

	SDL_Rect* sourceRect = new SDL_Rect();

	SDL_Event e;



	while (quit == false)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

		}

		if (mainStack->isUpdatePending())
		{
			mainStack->drawMap(0);
			mainStack->setUpdatePending(false);
		}

		Uint8* keystate = SDL_GetKeyState(NULL);
		ProcessKeys(keystate);

		sourceRect->h = SCREENHEIGHT;
		sourceRect->w = SCREENWIDTH;
		sourceRect->x = CAMERA_X;
		sourceRect->y = CAMERA_Y;

		int debug = SDL_BlitSurface(mainStack->getSurface(), sourceRect, screen, NULL);
		SDL_UpdateRect(screen, 0, 0, 0, 0);
		SDL_Flip(screen);
	}

	//SDL_Delay(2000);
	return 0;
}

