#pragma once

#include "../Component.h"

class PlayerAnimator;
class AnimationComponent;
class PlayerMovement : public Component
{
public:
	using Component::Component;
	virtual ~PlayerMovement() noexcept = default;

	virtual void	Init() override;
	virtual void	Update() override;

	void			SetSpeed(float speed) noexcept;

	float			GetSpeed() const noexcept;
private:
	float			_speed;
	float			_inertia = 100.0f; // 관성
	float			_velocity = 800.0f; // 중력가속도
	float			_gravity;
	POINT			_prevPos;
	PlayerAnimator* animator;
	AnimationComponent* anim;
};