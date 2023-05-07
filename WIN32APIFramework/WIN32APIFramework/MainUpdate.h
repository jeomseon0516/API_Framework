#pragma once
#ifndef __MAIN_UPDATE_H__
#define __MAIN_UPDATE_H__

#include "Include.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "DrawManager.h"
#include "Menu.h"

class MainUpdate
{
public:
	void Start();

	void Update() 
    { 
        DRAW_MANAGER->Update();
        GAME_MANAGER->Update(); 
    }
	 
    MainUpdate() { SCENE_MANAGER->SetScene(new Menu()); }
	 ~MainUpdate() {}
};
#endif