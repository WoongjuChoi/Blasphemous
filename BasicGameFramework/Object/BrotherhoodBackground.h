#pragma once

#include "GameObject.h"

class BrotherhoodBackground : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~BrotherhoodBackground() noexcept = default;

	virtual void Init() override;
};

