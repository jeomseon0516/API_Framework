#pragma once
#include "Include.h"
#include "Singleton.h"

class GameManager
{
	SINGLETON(GameManager)
	list<Singleton*> singletonList; // 싱글톤 생성시 자동으로 싱글톤 리스트에 담겨져 호출된다.

public:
	void Update()
	{
		for (list<Singleton*>::iterator iter = singletonList.begin(); iter != singletonList.end(); ++iter)
		{
			singletonList.emplace()->;
		}
	}
};

