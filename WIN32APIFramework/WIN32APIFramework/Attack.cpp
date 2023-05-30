#include "Attack.h"

#include "Idle.h"
#include "Character.h"

Attack* Attack::Start(Object* chr)
{
    Character* character = (Character*)chr;
    delete character->_state;
    character->_frame.locomotion = character->motionList["Attack"];
    character->_frame.countX = 0;

    return this;
}

void Attack::Action(Object* chr)
{
    Character* character = (Character*)chr;
    if (character->_frame.countX > character->_frame.locomotion.endFrameX)
    {
        delete character->_state;
        character->_state = new Idle();
        character->_frame.locomotion = character->motionList["Idle"];
        character->_frame.countX = 0;
    }
}
