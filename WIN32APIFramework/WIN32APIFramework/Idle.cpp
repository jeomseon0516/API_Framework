#include "Idle.h"
#include "Attack.h"
#include "Character.h"

Idle* Idle::Start(Object* chr)
{
    Character* character = (Character*)chr;
    delete character->_state;
    character->_frame.locomotion = character->motionList["Idle"];
    character->_frame.countX = 0;

    return this;
}

void Idle::Action(Object* chr)
{
    Character* character = (Character*)chr;
    if (abs(character->_direction.x) > 0.01f || abs(character->_direction.y) > 0.01f)
        character->_frame.locomotion = character->motionList["Run"];
    else
        character->_frame.locomotion = character->motionList["Idle"];

    if (INPUT_MANAGER->GetKey() & LEFT_CTRL)
        character->_state = (new Attack())->Start(character);
    if (INPUT_MANAGER->GetKey() & LEFT_SHIFT)
        character->_state = (new Acrobatics())->Start(character);
    if (INPUT_MANAGER->GetKey() & SPACE)
        character->_state = (new Jump())->Start(character);
}
