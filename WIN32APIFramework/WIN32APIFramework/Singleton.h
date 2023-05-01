#pragma once
#include "Include.h"

template <class T>
class Singleton
{
private:
	static T* _instance;
public:
	static T* GetInstance()
	{
		return _instance != nullptr ? _instance : _instance = new T();
	}
	
	virtual void Update() = 0;

protected:
	Singleton() {}
public:
	~Singleton() {}
};

template<class T> T* Singleton<T>::_instance = nullptr;