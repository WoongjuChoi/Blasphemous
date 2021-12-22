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
	void SetPos(float x, float y);

	RECT* GetRect() noexcept;

private:
	RECT			_rect;
	POINTFLOAT		_pos = { 0.0f, 0.0f };
	int				_width;
	int				_height;
};

