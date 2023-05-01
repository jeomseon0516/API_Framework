#pragma once
#include "Include.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Character.h"

class MainUpdate
{
private:
	Character* _character;
public:
	void Start();
	void Update();
	 
 	 MainUpdate() {}
	 ~MainUpdate() {}
};