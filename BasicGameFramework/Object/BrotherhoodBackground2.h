#pragma once

#include "GameObject.h"

class BrotherhoodBackground2 : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~BrotherhoodBackground2() noexcept = default;

	virtual void Init() override;
};
