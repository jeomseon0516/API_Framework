#include "Jump.h"
#include "Character.h"

Jump* Jump::Start(Object* chr)
{
    Character* character = (Character*)chr;
    delete character->_state;
    character->_frame.locomotion = character->motionList["Jump"];
    character->_frame.countX = 0;

    _startPosition = character->transform.position;
    _power = -10.0f;

    return this;
}

void Jump::Action(Object* chr)
{
    Character* character = (Character*)chr;

    character->transform.position.y += _power;
    _power += GRAVITY;

    if (_startPosition.y <= character->transform.GetMinY())
    {
        character->transform.position = _startPosition;
        character->_state = (new Idle())->Start(character);
    }
}

Jump::Jump() {}

Jump::~Jump() {}
