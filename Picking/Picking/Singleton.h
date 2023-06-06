#pragma once

// .. 클래스의 생성자를 정의하지 않아 외부에서 생성하지 못하게 합니다.
#define DO_NOT_MAKE(T)\
private:\
	T(const T&) = delete;\
	T& operator=(const T&)

// .. 싱글톤을 만들어주는 매크로 함수입니다.
#define SINGLETON(T)\
	DO_NOT_MAKE(T);\
private:\
    T();\
public:\
	static T** GetInstance()\
	{\
        static T* instance;\
		return instance ? &instance : &(instance = new T);\
	}\

// .. 전역 변수, static, extern 글로번 변수로 선언된 심볼릭 상수들은 모두 0으로 초기화 되기 때문에 nullptr초기화를 하지 않아도 nullptr체크가 된다.
#define GET_SINGLETON(T) (*T::GetInstance())

// .. 업데이트가 필요한 매니저 클래스는 해당 클래스를 상속 받습니다. 추상 클래스 이므로 상속받지 않으면 사용할 수 없습니다.
class Singleton
{
private:
    void SingletonStart();
    void(Singleton::*UpdateFunction)();
public:
    /*
        .. SingletonStart->Start->Update->함수를 순서로 호출됩니다. 가장 상위의 SingletonStart함수를 가장 먼저 호출 하는 이유는
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