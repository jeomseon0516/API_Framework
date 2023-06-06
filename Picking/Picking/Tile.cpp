#include "Tile.h"

Tile::Tile() : mineGame(nullptr) {}
Tile::~Tile() {}

// 게임 시작전에 주변 노드를 탐색해서 나의 노드 주변에 지뢰가 몇개있는지 탐색시키는게 낫지 않을까? 
Tile* Tile::Start(MineGame* _mineGame, int _countX, int _countY, bool _isBoom)
{
	_layerName = "Tile";

	mineGame = _mineGame;
	transform = Transform(Vector2(_countX, _countY), Vector2(TILE_SIZE, TILE_SIZE));

	numberMap.insert(make_pair(0, ZERO));
	numberMap.insert(make_pair(1, ONE));
	numberMap.insert(make_pair(2, TWO));
	numberMap.insert(make_pair(3, THREE));
	numberMap.insert(make_pair(4, FOUR));
	numberMap.insert(make_pair(5, FIVE));
	numberMap.insert(make_pair(6, SIX));
	numberMap.insert(make_pair(7, SEVEN));
	numberMap.insert(make_pair(8, EIGHT));

	aroundBoomCount = 0;

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