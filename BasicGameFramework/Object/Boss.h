#pragma once

#include "GameObject.h"

class Boss : public GameObject
{
public:
	using GameObject::GameObject;

	virtual void Init() override;
};