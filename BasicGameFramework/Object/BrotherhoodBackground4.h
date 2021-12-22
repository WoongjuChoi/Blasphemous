#pragma once

#include "GameObject.h"

class BrotherhoodBackground4 : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~BrotherhoodBackground4() noexcept = default;

	virtual void Init() override;
};
