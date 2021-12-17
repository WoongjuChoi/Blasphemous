#pragma once

#include "Scene.h"

class BrotherhoodScene : public Scene
{
	using Scene::Scene;

	virtual ~BrotherhoodScene() noexcept = default;

	virtual void Init() override;
};

