#include "Tile.h"

Tile::Tile() {}
Tile::~Tile() {}

Tile* Tile::Start(int _countX, int _countY)
{
	_layerName = "Tile";
	transform = Transform(Vector2(_countX, _countY), Vector2(TILE_SIZE, TILE_SIZE));
	isCurrent = false;

	image = IMAGE_MANAGER->GetFromKeyToImage("Tile");

	return this;
}

Tile* Tile::Start()
{
	_layerName = "Tile";
	transform = Transform(Vector2(WIN_SIZE_X, WIN_SIZE_Y) * 0.5f, Vector2(100, 100));
	isCurrent = false;

	image = IMAGE_MANAGER->GetFromKeyToImage("Tile");

	return this;
}

void Tile::Destroy()
{
}