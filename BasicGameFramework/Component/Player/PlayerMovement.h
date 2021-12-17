#pragma once

#include "../Component.h"

class PlayerMovement : public Component
{
public:
	using Component::Component;
	virtual ~PlayerMovement() noexcept = default;

	virtual void	Update() override;

	void			SetSpeed(float speed) noexcept;
	void			SetLoop(bool loopInfo) noexcept;

	float			GetSpeed() const noexcept;
private:
	float			_speed;
	float			_inertia = 200.0f; // °ü¼º
	float			_gravity = 800.0f;
	bool			isLoop = true;
	bool			isMovable = true;
};