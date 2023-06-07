#include "Tile.h"

Tile::Tile() : mineGame(nullptr), image(nullptr), aroundBoomCount(0), isBoom(false), isCheck(false), isCurrent(false) {}
Tile::~Tile() {}

Tile* Tile::Start(MineGame* _mineGame, int _countX, int _countY, bool _isBoom)
{
	_layerName = "Tile";

	mineGame = _mineGame;
	transform = Transform(Vector2(_countX, _countY), Vector2(TILE_SIZE, TILE_SIZE));

	numberMap[0] = ZERO;
	numberMap[1] = ONE;
	numberMap[2] = TWO;
	numberMap[3] = THREE;
	numberMap[4] = FOUR;
	numberMap[5] = FIVE;
	numberMap[6] = SIX;
	numberMap[7] = SEVEN;
	numberMap[8] = EIGHT;

	aroundBoomCount = 0; // key

	image = IMAGE_MANAGER->GetFromKeyToImage("Tile");
	imageFrame = DEFAULT;
	isCheck = isCurrent = false;
	isBoom = _isBoom;

	return this;
}

Tile* Tile::Start()
{
	_layerName = "Tile";
	transform = Transform(Vector2(WIN_SIZE_X, WIN_SIZE_Y) * 0.5f, Vector2(100, 100));
	isCurrent = false;

	isBoom = false;
	image = IMAGE_MANAGER->GetFromKeyToImage("Tile");

	return this;
}

void Tile::OpenNode()
{
	isCurrent = true;
	imageFrame = isBoom ? BOOM : imageFrame = numberMap[aroundBoomCount];
}