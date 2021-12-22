#pragma once

#include "GameObject.h"

class TitleBackground : public GameObject
{
public:
	using GameObject::GameObject;
	virtual ~TitleBackground() noexcept = default;

	virtual void Init() override;
};

