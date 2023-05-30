#include "Jump.h"
#include "Character.h"

Jump::Jump() {}
Jump::~Jump() {}

Jump* Jump::Start(Character* chr)
{
    delete chr->_state;

    chr->_frame.countX = 0;
    chr->_frame.locomotion = chr->motionList["Jump"];

    _keepY = chr->transform.position.y;
    _power = -15.0f;
    _isFall = false;

    return this;
}

void Jump::Action(Character* chr)
{
    chr->transform.position.y += _power;
    _power += GRAVITY;

    if (!_isFall && _power > FLT_EPSILON)
    {
        chr->_frame.countX = 0;
        chr->_frame.locomotion = chr->motionList["Fall"];
    }

    if (_keepY <= chr->transform.GetMinY())
    {
        chr->transform.position.y = _keepY;
        chr->_state = (new Idle())->Start(chr);
    }
}
