#pragma once
#include "Singleton.h"
#include "Object.h"
#include <vector>

using namespace std;

#define OBJECTMANAGER ObjectManager::GetInstance()

class ObjectManager : public Singleton<ObjectManager>
{
private:
	friend class Singleton<ObjectManager>;

	vector<Object*> _objectList;

public:
	Object* GetFromIndexToObject(int& index);

	void ObjectsInit();
	virtual void Update();

	int ObjectListSize() { return (int)_objectList.size(); }

	void PushBackObject(Object* object) { _objectList.push_back(object); }
	void RemoveFromIndexToObject(int index) { _objectList.erase(_objectList.begin() + index); }
private:
	ObjectManager() {}
};
