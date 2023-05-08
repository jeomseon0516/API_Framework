#include "Menu.h"

Menu::Menu()
{
    (new Object())->transform = Transform(Vector2(WIN_SIZE_X, WIN_SIZE_Y) * 0.5f, Vector2(500, 300));
}

Menu::~Menu()
{
}
