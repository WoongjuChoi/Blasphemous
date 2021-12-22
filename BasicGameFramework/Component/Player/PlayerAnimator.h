#pragma once

#include "../Component.h"

class PlayerAnimator : public Component
{
public:
	using Component::Component;
	virtual ~PlayerAnimator() noexcept = default;

	virtual void	Update() override;

	bool			GetIsMovable();

	void			SetIsMovable(bool state);
	void			SetOnGround(bool state);

private:
	bool			isLoop = true;
	bool			isMovable = true;
	bool			isOnGround = true;
};

