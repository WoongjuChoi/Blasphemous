#pragma once

#include "GameObject.h"

class BrotherhoodBackground1 : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~BrotherhoodBackground1() noexcept = default;

	virtual void Init() override;
};

