#include "Main.h"

Main::Main() {}
Main::~Main() 
{
	delete mineGame;
	mineGame = nullptr;
}

void Main::Start()
{
	mineGame = (new MineGame())->Start();
}