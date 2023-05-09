#pragma once
#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include <vector>
#include <list>
#include <map>
#include <string>
#include <Windows.h>

#include "Define.h"
#include "Mathf.h"

#undef PURE
#define PURE = 0

#define WIN_SIZE_X 1500
#define WIN_SIZE_Y 720

// 벡터를 관리하는 매크로 함수 입니다. 기본적으로 요소의 위치를 알고 있다는 전제하에 만들어진 함수 입니다. 또한 index는 참조값으로 --index를 동작 시킵니다.
// 이렇게 사용할게 아니라면 함수 호출 후 ++index를 시켜주어야 합니다.
// .. 벡터의 요소를 가져와 벡터에서 제거 시킵니다..
#define ELEMENT_ERASE(T, INDEX, VECTOR)\
VECTOR.erase(VECTOR.begin() + INDEX);\
--INDEX

// TODO : .. 메모리 누수 위험
// .. 특정 조건을 만족시켰을때 벡터의 요소를 벡터에서 제거 시킵니다.. 함수 호출을 하기전에 요소를 다른 곳에다 저장해두어야 합니다.
#define ELEMENT_ERASE_TO_CONDITION(T, CONDITION, INDEX, VECTOR)\
if (CONDITION)\
{\
    ELEMENT_ERASE(T, INDEX, VECTOR);\
}

// .. 벡터의 요소들을 모두 메모리 해제 후 벡터에서 erase합니다. 메모리를 아예 해제하니 주의해야 합니다.
#define CLEAR_VECTOR(T, VECTOR)\
for (int i = 0; i < VECTOR.size(); ++i)\
    RELEASE_ELEMENT(T, true, i, &VECTOR)

// .. 해당 함수는 벡터의 요소가 특정 조건일때 벡터의 요소에서 제거하고 메모리까지 해제시키는 역할을 합니다.
#define RELEASE_ELEMENT(T, CONDITION, INDEX, VECTOR)\
[](bool condition, int& index, vector<T*>* objectList)\
{\
    if (!condition) return false;\
    delete objectList->at(index);\
    ELEMENT_ERASE(T, index, (*objectList));\
    return true;\
}(CONDITION, INDEX, VECTOR)

//  TODO : .. 메모리 누수 위험
/*
    .. 삭제시킨 벡터의 요소를 또 다른 벡터 에다가 다시 넣어줍니다.Destroy를 위한 함수입니다.
    catchList에 들어간 벡터의 요소는 자유롭게 사용이 가능하지만 Destroy를 하기전에 필요한 동작들을 수행하고
    마지막에 catchList에 있는 요소들을 메모리 해제 시키기 위해 만든 함수입니다.
    catchList에 있는 요소들을 처리해주지 않으면 메모리 누수가 발생합니다.
*/
#define CATCH_RELASE_ELEMENT(T, CONDITION, INDEX, REMOVE_VECTOR, CATCH_VECTOR)\
[](bool condition, int& index, vector<T*>* removeList, vector<T*>* catchList)\
{\
    if (!condition) return false;\
    catchList->push_back(removeList->at(index)); \
    ELEMENT_ERASE(T, index, (*removeList));\
    return true;\
}(CONDITION, INDEX, REMOVE_VECTOR, CATCH_VECTOR)

using namespace std;
#endif