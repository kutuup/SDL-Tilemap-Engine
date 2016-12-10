#include "stdafx.h"
#include "TileLibraryEntry.h"
#include "SDL.h"

void TileLibraryEntry::setImage(SDL_Surface* img)
{
	image = img;
}

void TileLibraryEntry::setID(int id)
{
	this->id = id;
}

int TileLibraryEntry::getID()
{
	return id;
}

SDL_Surface* TileLibraryEntry::getImage()
{
	return image;
}

TileLibraryEntry::TileLibraryEntry()
{
}


TileLibraryEntry::~TileLibraryEntry()
{
}
