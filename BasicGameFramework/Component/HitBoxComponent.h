#pragma once

#include <Windows.h>

#include "Component.h"

class HitBoxComponent : public Component
{
public:
	using Component::Component;
	virtual ~HitBoxComponent() noexcept = default;

	virtual void	Update() override;
	virtual void	Render(HDC hdc) override;

	void SetSize(int width, int height) noexcept;

	RECT* GetRect() noexcept;

private:
	RECT			_rect;
	int				_width;
	int				_height;
};

