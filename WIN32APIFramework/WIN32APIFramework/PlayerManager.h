#pragma once
#ifndef __PLAYER_MANAGER_H__
#define __PLAYER_MANAGER_H__

#include "Singleton.h"
#include "Include.h"
#include "Character.h"

#define PLAYERMANAGER PlayerManager::GetInstance()

class PlayerManager : public Singleton
{
private:
	Character* _character;
	SINGLETON(PlayerManager)
};
#endif