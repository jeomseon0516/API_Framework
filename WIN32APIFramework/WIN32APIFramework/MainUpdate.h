#pragma once
#ifndef __MAIN_UPDATE_H__
#define __MAIN_UPDATE_H__

#include "Include.h"
#include "PlayerManager.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "DrawManager.h"
#include "Main.h"

class MainUpdate
{
public:
	void Start();

	void Update() 
    { 
        DRAW_MANAGER->Update();
        GAME_MANAGER->Update(); 
    }
	 
    MainUpdate();
    ~MainUpdate();
};
#endif