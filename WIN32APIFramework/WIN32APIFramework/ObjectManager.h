#pragma once
#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

#include "Include.h"
#include "Singleton.h"

using namespace std;

class Object;

#define OBJECTMANAGER ObjectManager::GetInstance()

class ObjectManager : public Singleton
{
	SINGLETON(ObjectManager)

	vector<Object*> _objectList;

public:
	Object* GetFromIndexToObject(int& index);

	int ObjectListSize() { return (int)_objectList.size(); }

	void PushBackObject(Object* object) { _objectList.push_back(object); }
	void RemoveFromIndexToObject(int index) { _objectList.erase(_objectList.begin() + index); }
};

#endif