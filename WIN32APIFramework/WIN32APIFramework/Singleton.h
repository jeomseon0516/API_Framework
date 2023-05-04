#pragma once
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#define DO_NOT_MAKE(CLASSNAME)\
private:\
	CLASSNAME(const CLASSNAME&);\
	CLASSNAME& operator=(const CLASSNAME&); // 연산자 오버로딩으로 정의하지 않아 생성 제한

#define SINGLETON(CLASSNAME)\
	DO_NOT_MAKE(CLASSNAME)\
	static CLASSNAME* instance; \
	 CLASSNAME();\
	 virtual ~CLASSNAME();\
public:\
	static CLASSNAME* GetInstance()\
	{\
		return instance = instance != nullptr ? instance : new CLASSNAME;\
	}\
	void ReleaseInstance()\
	{\
		delete instance;\
		instance = nullptr;\
	}\
	void Update();

#define SINGLETON_INIT(CLASSNAME)\
\
CLASSNAME* CLASSNAME::instance = nullptr;

class Singleton
{
private:
	Singleton();
	virtual ~Singleton() {}
};
#endif