#include "Main.h"

Main::Main() {}
Main::~Main() {}

void Main::Start()
{
	int wx = WIN_SIZE_X / TILE_SIZE, wy = WIN_SIZE_Y / TILE_SIZE;

	for (int i = 0; i < wx * wy; ++i)
		tileList.push_back((new Tile())->Start(TILE_SIZE * 0.5f + TILE_SIZE * (i % wx), TILE_SIZE * 0.5f + TILE_SIZE * (i / wx)));
}