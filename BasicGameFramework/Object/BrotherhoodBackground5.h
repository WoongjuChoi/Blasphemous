#pragma once

#include "GameObject.h"

class BrotherhoodBackground5 : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~BrotherhoodBackground5() noexcept = default;

	virtual void Init() override;
};
