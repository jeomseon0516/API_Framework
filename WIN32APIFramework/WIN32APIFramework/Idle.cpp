#include "Idle.h"
#include "Attack.h"
#include "Character.h"

Idle* Idle::Start(Character* chr)
{
    delete chr->_state;
    chr->_frame.locomotion = chr->motionList["Idle"];
    chr->_frame.countX = 0;

    return this;
}

void Idle::Action(Character* chr)
{
    if (abs(chr->_direction.x) > 0.01f || abs(chr->_direction.y) > 0.01f)
        chr->_frame.locomotion = chr->motionList["Run"];
    else
        chr->_frame.locomotion = chr->motionList["Idle"];

    if (INPUT_MANAGER->GetKey() & LEFT_CTRL)
        chr->_state = (new Attack())->Start(chr);
    if (INPUT_MANAGER->GetKey() & LEFT_SHIFT)
        chr->_state = (new Acrobatics())->Start(chr);
    if (INPUT_MANAGER->GetKey() & SPACE)
        chr->_state = (new Jump())->Start(chr);
}
