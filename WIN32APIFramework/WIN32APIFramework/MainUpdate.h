#pragma once
#ifndef __MAIN_UPDATE_H__
#define __MAIN_UPDATE_H__

#include "Include.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "Character.h"
#include "Enemy.h"

class MainUpdate
{
public:
	void Start();
	void Update();
	 
 	 MainUpdate() {}
	 ~MainUpdate() {}
};

#endif