#pragma once

#include "GameObject.h"

class TitlePenitentOneAnim : public GameObject
{
public: 
	using GameObject::GameObject;
	virtual ~TitlePenitentOneAnim() noexcept = default;

	virtual void Init() override;
};

