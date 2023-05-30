#include "Acrobatics.h"
#include "Character.h"

Acrobatics::Acrobatics()  {}
Acrobatics::~Acrobatics() {}

Acrobatics* Acrobatics::Start(Character* chr)
{
    delete chr->_state;

    chr->_frame.locomotion = chr->motionList["Acrobatics"];
    chr->_frame.countX = 0;

    return this;
}

void Acrobatics::Action(Character* chr)
{
    if (chr->_frame.countX > chr->_frame.locomotion.endFrameX)
        chr->_state = (new Idle())->Start(chr);
}