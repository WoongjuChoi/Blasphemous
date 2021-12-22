#pragma once

#include "GameObject.h"

class BrotherhoodBackground3 : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~BrotherhoodBackground3() noexcept = default;

	virtual void Init() override;
};
