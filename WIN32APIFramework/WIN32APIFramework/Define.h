#pragma once
#define _CRT_SECURE_NO_WARNINGS 0

#include "Mathf.h"

#define DEBUG

#undef PURE
#define PURE = 0

#define WIN_SIZE_X 710
#define WIN_SIZE_Y 986

// 벡터를 관리하는 매크로 함수 입니다. 기본적으로 요소의 위치를 알고 있다는 전제하에 만들어진 함수 입니다. 또한 index는 참조값으로 --index를 동작 시킵니다.
// 이렇게 사용할게 아니라면 함수 호출 후 ++index를 시켜주어야 합니다.
// .. 벡터의 요소를 가져와 벡터에서 제거 시킵니다..
#define ELEMENT_ERASE(T, LIST, ITER)\
ITER = LIST.erase(ITER)

// TODO : .. 메모리 누수 위험
// .. 특정 조건을 만족시켰을때 리스트의 요소를 리스트에서 제거 시킵니다.. 함수 호출을 하기전에 요소를 다른 곳에다 저장해두어야 합니다.
#define ELEMENT_ERASE_TO_CONDITION(T, CONDITION, LIST, ITER)\
[](bool condition, list<T*>* anyList, list<T*>::iterator& iter)\
{\
    if (!condition) return true;\
    ELEMENT_ERASE(T, (*anyList), iter);\
    return false;\
}(CONDITION, LIST, ITER)

// .. 벡터의 요소들을 모두 메모리 해제 후 벡터에서 erase합니다. 메모리를 해제하니 주의해야 합니다.
#define CLEAR_LIST(T, LIST)\
for (T* item : LIST)\
    delete item;\
LIST.clear()

// .. 해당 함수는 리스트의 요소가 특정 조건을 만족할때 벡터에서 제거하고 메모리를 해제시키는 역할을 합니다.
#define RELEASE_ELEMENT(T, CONDITION, LIST, ITER)\
[](bool condition, list<T*>* anyList, list<T*>::iterator& iter)\
{\
    if (!condition) return true;\
    delete (*iter);\
    ELEMENT_ERASE(T, (*anyList), iter);\
    return false;\
}(CONDITION, LIST, ITER)

extern HWND g_hWnd;