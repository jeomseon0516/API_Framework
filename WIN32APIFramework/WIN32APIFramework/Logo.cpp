#include "Logo.h"

Logo::Logo()
{
    (new Object)->transform = Transform(Vector2(WIN_SIZE_X, WIN_SIZE_Y) * 0.5f, Vector2(100, 200));
}

Logo::~Logo() {}
