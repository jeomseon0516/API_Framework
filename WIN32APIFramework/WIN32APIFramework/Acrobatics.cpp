#include "Acrobatics.h"
#include "Character.h"

Acrobatics* Acrobatics::Start(Object* chr)
{
    Character* character = (Character*)chr;
    delete character->_state;
    character->_frame.locomotion = character->motionList["Acrobatics"];
    character->_frame.countX = 0;

    return this;
}

void Acrobatics::Action(Object* chr)
{
    Character* character = (Character*)chr;

    if (character->_frame.countX > character->_frame.locomotion.endFrameX)
        character->_state = (new Idle())->Start(character);
}

Acrobatics::Acrobatics() {}

Acrobatics::~Acrobatics() {}
