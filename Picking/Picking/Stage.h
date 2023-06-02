#pragma once
#include "Include.h"

class Stage
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

public:
	Stage();
	virtual ~Stage();
};

