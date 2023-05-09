#pragma once
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

// .. 클래스의 생성자를 정의하지 않아 외부에서 생성하지 못하게 합니다.
#define DO_NOT_MAKE(CLASSNAME)\
private:\
	CLASSNAME(const CLASSNAME&);\
	CLASSNAME& operator=(const CLASSNAME&);

// 싱글톤을 만들어주는 매크로 함수입니다.
#define SINGLETON(CLASSNAME)\
	DO_NOT_MAKE(CLASSNAME)\
	static CLASSNAME* instance;\
	CLASSNAME();\
public:\
	static CLASSNAME* GetInstance()\
	{\
		return instance != nullptr ? instance : instance = new CLASSNAME;\
	}\
	void ReleaseInstance()\
	{\
		delete instance;\
		instance = nullptr;\
	}

// 싱글톤을 사용하는 클래스는 cpp파일에 해당 함수를 호출 해주어야 합니다.
#define SINGLETON_INIT(CLASSNAME)\
CLASSNAME* CLASSNAME::instance = nullptr;

class Singleton
{
private:
    void SingletonStart();
    void(Singleton::* UpdateFunction)();
public:
    /*
        ** SingletonStart->Start->Update->함수를 순서로 호출됩니다. 가장 상위의 SingletonStart함수를 가장 먼저 호출 하는 이유는
        생성자의 함수 호출 순서 때문입니다. 생성자의 호출 순서는 부모의 생성자 -> 자식의 생성자 입니다. 생성자에서 Start함수를 함수 포인터에 초기화시키면 오버라이드 된 Start가 아닌
        부모 객체의 Start함수로 초기화가 되기때문에 SlngletonStart함수를 함수 포인터에 넣어주고 자식의 생성자가 모두 호출된 후에 SingletonStart 함수에서 Start를 호출되게 만듭니다.
        때문에 해당 객체를 상속받는 모든 클래스는 Start 이후 Update가 자동으로 호출됩니다.
        Start, Update함수는 더 이상 외부에서 호출할 필요가 없기때문에 protected 또는 private으로 외부에서 호출되지 않게 합니다.
    */
    void SingletonUpdate() { (this->*UpdateFunction)(); }
    virtual ~Singleton();

protected:

    virtual void Update() = 0;
    virtual void Start();

    Singleton();
} typedef UpdatingSingleton;
#endif