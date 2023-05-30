#include "Attack.h"

#include "Idle.h"
#include "Character.h"

Attack* Attack::Start(Character* chr)
{
    delete chr->_state;
    chr->_frame.countX = 0;

    chr->_frame.locomotion = chr->motionList["Attack"];

    return this;
}

void Attack::Action(Character* chr)
{
    if (chr->_frame.countX > chr->_frame.locomotion.endFrameX)
        chr->_state = (new Idle())->Start(chr);
}
